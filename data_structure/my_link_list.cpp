/*
 * 单向列表
 * 采用一个个相连的节点存放数据，在单项列表中一个结点只有一个指向下一节点的指针。
 * */

#include <iostream>
#include <stdexcept>
#define MAX_CAP 65536
using namespace std;

template<class T>
class MyLinkNode{
    public:
        T element;
        MyLinkNode* next;
        MyLinkNode() { this->next = nullptr; }
        MyLinkNode(T element) { 
            this->next = nullptr; 
            this->element = element; 
        }
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
        void remove(int i);
        int index_of(T t);
        void show();

    private:
        MyLinkNode<T> *head;
        int N;
};

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
       N--;
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
    if(N>=MAX_CAP){
        cout << "列表长度以达到最大限值，无法添加！！！"<<endl;
        throw  "列表长度以达到最大限值，无法添加！！！";
    }
    if(N++ == 0){
        head = new MyLinkNode<T>(t);
        return;
    }
    MyLinkNode<T> *p = head;
    while(p->next != nullptr){p = p->next;}
    p->next = new MyLinkNode<T>(t);
}

template <class T> void MyLinkList<T>::insert(int i, T t) {
    if(N>=MAX_CAP){
        cout << "列表长度以达到最大限值，无法添加！！！"<<endl;
        throw  "列表长度以达到最大限值，无法添加！！！";
    }
    if(i > N){
        cout << "超出范围"<<endl;
        throw "超出范围";
    }
    MyLinkNode<T> *pp = nullptr;
    MyLinkNode<T> *p = head;
    for(int j=0; j < i; j++){
        pp = p;
        p = p->next; 
    }
    if (pp == nullptr){
        head = new MyLinkNode<T>(t);
        head->next = p;
    }else{
        pp->next = new MyLinkNode<T>(t);\
        pp->next->next = p;
    }
    N++;
}

template <class T> void MyLinkList<T>::remove(int i) {
    if(i > N-1){
        cout << "超出范围"<<endl;
        throw "超出范围";
        return;
    }
    MyLinkNode<T> *pp = nullptr;
    MyLinkNode<T> *p = head;
    for(int j=0; j < i; j++){
        pp = p;
        p = p->next; 
    }
    if (pp == nullptr){
        head = p->next;
        delete p;
    }else{
        pp->next = p->next;
        pp->next->next = p;
        delete p;
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
    cout<<"\n列表长度："<<N<<endl;
    if(head==nullptr){
        cout<<"\n[异常]列表为空。\n"<<endl;
        return;
    }
    cout<<"列表内容："<<endl;
    for(MyLinkNode<T> *p = head; p!=nullptr; p=p->next){
        cout<<p->element<<"->";
    }
    cout<<"null"<<"\n"<<endl;
}

int main(){
    MyLinkList<int> ml;
    ml.show();
    for (int i = 0; i < 64; i++) {
        ml.insert(i);
    }
    ml.show();
    cout << "第一个2在：" << ml.get(2) << endl;
    ml.insert(0, 1);
    cout<<"再插入1个数"<<endl;
    ml.show();
    cout<<"删除1个数"<<endl;
    ml.remove(0);
    ml.show();
    try{ml.insert(65537, 2);}catch(...){
        cout<<"出现异常。"<<endl;
    }
    cout<<"执行完毕"<<endl;
    return 0;
}
