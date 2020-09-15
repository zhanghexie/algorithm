/**
 * 二叉树
 *
 **/
#ifndef MY_BINARY_TREE
#define MY_BINARY_TREE
#define MAX_CAP 65536
#include <iostream>
using namespace std;

template<class K, class V>
class MyBinaryNode{
    public:
        K key;
        V value;
        MyBinaryNode<K, V> *left;
        MyBinaryNode<K, V> *right;
        MyBinaryNode(K key, V value);
        MyBinaryNode(MyBinaryNode<K,V> *left,MyBinaryNode<K,V> *right, K key, V value);
};

template<class K, class V>
class MyBinaryTree{
    public:
        MyBinaryTree();
        int size();
        void put(K key, V value);
        V get(K key);
    private:
        MyBinaryNode<K, V> *head;
        int N;
};

// 节点部分
template<class K, class V> 
MyBinaryNode<K,V>::MyBinaryNode(MyBinaryNode<K,V> *left,MyBinaryNode<K,V> *right, K key, V value){
    this->left = left;
    this->right = right;
    this->key = key;
    this->value = value;
}

template<class K, class V> 
MyBinaryNode<K, V>::MyBinaryNode(K key, V value){
    this->left = nullptr;
    this->right = nullptr;
    this->key = key;
    this->value = value;
} 

// 树部分
template<class K, class V>
MyBinaryTree<K, V>::MyBinaryTree(){
    N = 0;
    head = nullptr;
}

template<class K, class V>
int MyBinaryTree<K, V>::size(){
    return N;
}

template<class K, class V>
void MyBinaryTree<K, V>::put(K key, V value){
    if (N > MAX_CAP){
        cout << "超出容量！！！" << endl;
        throw "超出容量！！！";
    }
    MyBinaryNode<K, V> *temp = head;
    while (temp != nullptr) {
        if(key>temp->key){
            temp=temp->right;
        }else{
            temp=temp->left;
        }
    }
    temp = new MyBinaryNode<K, V>(key,value);
    N++;
}

template<class K, class V>
V MyBinaryTree<K, V>::get(K key){   
    MyBinaryNode<K, V> *temp = head;
    while (temp != nullptr) {
        if(key == temp->key){
            return temp->value;
        }else if(key > temp->key){
            temp = temp->right;
        }else{
            temp = temp->left;
        }
    }
    cout << "没有找到！" << endl;
    throw "没找到！";
}

#endif
