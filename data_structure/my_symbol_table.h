/*
 * 符号表
 * 存储的元素是一个键和一个值组成的键值对。
 * */
#ifndef MY_SYMBOL_TABLE
#define MY_SYMBOL_TABLE
#define MAX_CAP 65536

#include<iostream>
using namespace std;

template<class K, class V>
class MySymbolNode{

    public:
        MySymbolNode<K,V> *next;
        K key;
        V value;
        MySymbolNode();
        MySymbolNode(K key, V value);
        ~MySymbolNode();
};


template<class K, class V>
class MySymbolTable{

    public:
        MySymbolTable();
        ~MySymbolTable();
        void insert(K key, V value);
        V get(K key);
        void remove(K key);
        int size(){return N;} 
        void show();

    private:
        MySymbolNode<K,V> *head;
        MySymbolNode<K,V> *tail;
        int N;
        MySymbolNode<K, V>* find_key(K key);
};

// 节点部分
template<class K, class V> MySymbolNode<K, V>::MySymbolNode(){
    next = nullptr;
}

template<class K, class V> MySymbolNode<K, V>::~MySymbolNode(){}

template<class K, class V> MySymbolNode<K, V>::MySymbolNode(K key, V value){
    this->key = key;
    this->value = value;
    this->next = nullptr;
}

// 数据表部分
template<class K, class V> MySymbolTable<K, V>::MySymbolTable(){
    this->head = nullptr;
    this->tail = nullptr;
    this->N = 0;
}

template<class K, class V> MySymbolTable<K, V>::~MySymbolTable(){}

template<class K, class V> MySymbolNode<K, V> *MySymbolTable<K, V>::find_key(K key){    
    if (N==0){
        throw "找不到！";
        return nullptr;
    }
    if(head->key == key){
        return nullptr;
    }
    MySymbolNode<K, V> *temp = head;
    for(;temp->next != nullptr; temp = temp->next){
        if(temp->next->key == key){
            cout<<"有"<<endl;
            return temp;
        }
    }
    throw "找不到！";
    return nullptr;
}

template<class K, class V> void MySymbolTable<K, V>::insert(K key, V value){
    if(N >= MAX_CAP){
        cout<<"到达容量上限，无法插入"<<endl;
        throw "到达容量上限，无法插入";
    }else{
        if(0 == N){
            head = new MySymbolNode<K, V>(key, value);
            tail = head;
            N++;
        }else{
            try {
                find_key(key);
                cout<<"key:"<<key<<",已存在，无法插入！"<<endl;
            } catch (...) {
                tail->next = new MySymbolNode<K, V>(key, value);
                tail = tail->next;
                N++;
            }
        }
    }
}

template<class K, class V> V MySymbolTable<K, V>::get(K key){
    try {
        MySymbolNode<K, V> *temp = find_key(key);
        if(temp == nullptr){
            return head->value;
        }else{
            return temp->next->value;
        }
    } catch (...) {
        cout << "未找到"<<endl;     
        throw "未找到";     
    }
}

template<class K, class V> void MySymbolTable<K, V>::remove(K key){
    try {
        MySymbolNode<K, V> *temp;
        MySymbolNode<K, V> *pp = find_key(key);
        if(pp==nullptr){
            temp = head;
            head = head->next;
            delete temp;
            N--;
        }else if(pp->next == tail){
            tail = pp;
            delete pp->next;
            N--;
        }else{
            temp = pp->next;
            pp->next = temp->next;
            delete temp;
            N--;
        }
    } catch (...) {
        cout << "未找到" << endl;     
        throw "未找到";     
    }
}

template<class K, class V> void MySymbolTable<K, V>::show(){
    if(N==0){
        cout<<"为空！"<<endl;
    }else{
        for(MySymbolNode<K, V> *temp=head; temp != nullptr; temp=temp->next){
             cout<<temp->key << "：" << temp->value << endl;
        }
        cout<<endl;
    }
}
#endif
