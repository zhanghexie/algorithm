/*
 * 单向列表
 * 采用一个个相连的节点存放数据，在单项列表中一个结点只有一个指向下一节点的指针。
 * */

#ifndef MY_LINK_LIST 
#define MY_LINK_LIST 
#define MAX_CAP 65536
#include <iostream>
#include <stdexcept>
#define MAX_CAP 65536
using namespace std;


template<class T>
class MyLinkNode{
    public:
        T element;
        MyLinkNode* next;
        MyLinkNode();
        MyLinkNode(T element);
};

template <class T> class MyLinkList {
    public:
        MyLinkList();
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
        MyLinkNode<T> *head;
        int N;
};


template<class T> MyLinkNode<T>::MyLinkNode(){ 
        this->next = nullptr; 
    }
template<class T> MyLinkNode<T>::MyLinkNode(T element) { 
            this->next = nullptr; 
            this->element = element; 
        }
template <class T> MyLinkList<T>::MyLinkList() {
    N = 0;
    head = nullptr;
}

template <class T> void MyLinkList<T>::clear() {
    N = 0;
    MyLinkNode<T> *p = head;
    MyLinkNode<T> *d = head;
    while(p != nullptr){
       p = p->next;
       delete d;
       d = p;
    }
}

template <class T> bool MyLinkList<T>::is_empty() { return 0 == N; }

template <class T> int MyLinkList<T>::length() { return N; }

template <class T> T MyLinkList<T>::get(int i) {
    int j = 0;
    MyLinkNode<T> *p = head;
    while(j < i){
        j++;
        p = p->next;
    }
    return p->element;
}

template <class T> void MyLinkList<T>::insert(T t) {
    insert(length(),t);
}

template <class T> void MyLinkList<T>::insert(int i, T t) {
    if(N>=MAX_CAP){
        cout << "列表长度以达到最大限值，无法添加！！！"<<endl;
        throw  "列表长度以达到最大限值，无法添加！！！";
        return;
    }
    if(i>N || i<0){
        cout << "超出范围"<<endl;
        throw "超出范围";
        return;
    }
    MyLinkNode<T> *tmp = new MyLinkNode<T>(t);
    // 长度为零，并且在0处插入。
    if(i==0 && N==0){
        head = tmp;
    // 长度不为零，在0处插入。
    }else if(i==0){
        tmp->next = head;
        head = tmp;
    // 长度不为零，不在0处插入。
    }else{
        MyLinkNode<T> *p = head;
        for(int j = 0; j < i-1; j++){
            p = p->next;
        }
        tmp->next = p->next;
        p->next = tmp;
    }
    N++;
}

template <class T> void MyLinkList<T>::remove() {
    remove(length()-1);
}
template <class T> void MyLinkList<T>::remove(int i) {
    if(i>N-1 || i<0){
        cout << "超出范围"<<endl;
        throw "超出范围";
        return;
    }
    if(i==0 && N==1){
        delete head;
        head = nullptr;
    }else if(i==0){
        MyLinkNode<T> *tmp = head;
        head = head->next;
        delete tmp;
    }else{
        MyLinkNode<T> *p = head;
        for(int j = 0; j < i-1; j++){
            p = p->next;
        }
        MyLinkNode<T> *tmp = p->next;
        p->next = tmp->next;
        delete tmp;
    }
    N--;
}
template <class T> int MyLinkList<T>::index_of(T t) {
    int i = 0;
    for(MyLinkNode<T> *p = head; p!=nullptr; p=p->next){
        if (p->element == t) return i;
        i++;
    }
}

template <class T> void MyLinkList<T>::show() {
    cout<<"列表长度："<<N<<endl;
    if(head==nullptr){
        cout<<"列表为空。\n"<<endl;
        return;
    }
    cout<<"列表内容："<<endl;
    for(MyLinkNode<T> *p = head; p!=nullptr; p=p->next){
        cout<<p->element<<"->";
    }
    cout<<"null"<<"\n"<<endl;
}

#endif
