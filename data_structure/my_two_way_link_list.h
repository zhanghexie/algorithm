/*
 * 双向列表
 * 采用一个个相连的节点存放数据，在双项列表中一个结点指向前后两个节点指针。
 * */
#ifndef IMPORT
#define IMPORT
#include <ctime>
#include <ios>
#include <iostream>
#include <stdexcept>
#define MAX_CAP 65536
using namespace std;

template<class T>
class MyTwoWayLinkNode{
    public:
        T element;
        MyTwoWayLinkNode* next;
        MyTwoWayLinkNode* pre;
        MyTwoWayLinkNode();
        MyTwoWayLinkNode(T element);
};

template <class T> class MyTwoWayLinkList {
    public:
        MyTwoWayLinkList();
        void clear();
        bool is_empty();
        int length();
        T get(int i);
        void insert(T t);
        void insert(int i, T t);
        void remove();
        void remove(int i);
        int index_of(T t);
        void show();

    private:
        MyTwoWayLinkNode<T> *head;
        MyTwoWayLinkNode<T> *tail;
        int N;
};

template<class T> MyTwoWayLinkNode<T>::MyTwoWayLinkNode() { 
            this->pre = nullptr; 
            this->next = nullptr; 
        }

template<class T> MyTwoWayLinkNode<T>::MyTwoWayLinkNode(T element) { 
    this->pre = nullptr; 
    this->next = nullptr; 
    this->element = element; 
}

template <class T> MyTwoWayLinkList<T>::MyTwoWayLinkList() {
    N = 0;
    head = nullptr;
    tail = nullptr;
}

template <class T> void MyTwoWayLinkList<T>::clear() {
    N = 0;
    MyTwoWayLinkNode<T> *p = head;
    MyTwoWayLinkNode<T> *pp = head;
    while(p != nullptr){
       p = p->next;
       delete pp;
       pp = p;
    }
}

template <class T> bool MyTwoWayLinkList<T>::is_empty() { return 0 == N; }

template <class T> int MyTwoWayLinkList<T>::length() { return N; }

template <class T> T MyTwoWayLinkList<T>::get(int i) {
    if(i>=N){
        cout << "[异常]超出范围!" << endl;
        throw "[异常]超出范围!";
        return 0;
    }
    int j = 0;
    MyTwoWayLinkNode<T> *p = head;
    while(j < i){
        j++;
        p = p->next;
    }
    return p->element;
}

template <class T> void MyTwoWayLinkList<T>::insert(T t) {
    insert(length(),t);
}

template <class T> void MyTwoWayLinkList<T>::insert(int i, T t) {
    if(N>=MAX_CAP){
        cout << "列表长度以达到最大限值，无法添加！！！"<<endl;
        throw  "列表长度以达到最大限值，无法添加！！！";
    }
    if(i>N || i<0){
        cout << "[异常]超出范围"<<endl;
        throw "超出范围";
    }

    MyTwoWayLinkNode<T> *tmp = new MyTwoWayLinkNode<T>(t);
    // 链表为空，并且在第一位插入。
    if(i==0 && N==0){
        head = tmp;
        tail = head;
    // 链表不为空，并且在第一位插入。
    }else if(i == 0){
        tmp->next = head;
        head->pre = tmp;
        head = tmp;
    // 链表不为空，并且在最后一位插入。
    }else if(i == N){
        tmp->pre = tail;
        tail->next = tmp;
        tail = tmp;
    // 链表不为空，并且在中间插入。
    }else{
        MyTwoWayLinkNode<T> *p = nullptr;
        if(i>N/2){
            p = tail;
            for(int j=N-1; j>i; j--){
                p = p->pre;
            }
        }else{
            p = head;
            for(int j=0; j<i; j++){
                p = p -> next;
            }
        }
        tmp->next = p;
        tmp->pre = p->pre;
        p->pre->next = tmp;
        p->pre = tmp;
    }
    N++;
}

template <class T> void MyTwoWayLinkList<T>::remove() {
    remove(length()-1);
}
template <class T> void MyTwoWayLinkList<T>::remove(int i) {
    if(i > N-1 || i<0){
        cout << "[异常]超出范围"<<endl;
        throw "超出范围";
        return;
    }
    // 链表长度为1
    if(i==0 && N==1){
        head->next = nullptr;
        tail->pre = nullptr;
        delete head;
    // 链表长度大于一，删除第一个。
    }else if(i == 0){
        head = head->next;
        delete head->pre;
        head->pre = nullptr;
    // 链表长度大于一，删除最后一个。
    }else if(i == N-1){
        tail = tail->pre;
        delete tail->next;
        tail->next = nullptr;
    // 链表长度大于一，删除中间一个。
    }else{
        MyTwoWayLinkNode<T> *p = nullptr;
        if(i>N/2){
            p = tail;
            for(int j=N-1; j>i; j--){
                p = p->pre;
            }
        }else{
            p = head;
            for(int j=0; j<i; j++){
                p = p -> next;
            }
        }
        p->pre->next = p->next;
        p->next->pre = p->pre;
        delete p;
    }
    N--;
}
template <class T> int MyTwoWayLinkList<T>::index_of(T t) {
    int i = 0;
    for(MyTwoWayLinkNode<T> *p = head; p!=nullptr; p=p->next){
        if (p->element == t) return i;
        i++;
    }
}

template <class T> void MyTwoWayLinkList<T>::show() {
    cout<<"\n列表长度："<<N<<endl;
    if(head==nullptr){
        cout<<"链表为空。"<<endl;
        return;
    }
    cout<<"列表内容："<<endl;
    cout<<"null->";
    for(MyTwoWayLinkNode<T> *p = head; p!=nullptr; p=p->next){
        cout<<p->element<<"<->";
    }
    cout<<"\b\b\b->null"<<"\n"<<endl;
}

#endif
