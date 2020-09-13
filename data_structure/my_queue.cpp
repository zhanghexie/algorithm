/*
 * 队列
 * 先进先出的数据结构。
 * */

#include <iostream>
#include <stdexcept>
#include "my_link_list.h"
#define MAX_CAP 65536

using namespace std;

template <class T> class MyQueue {
    public:
        MyQueue();
        int size();
        bool is_empty();
        void enqueue(T t);
        T dequeue();
        void show();

    private:
        int N;
        MyLinkList<T> ml;
};

template <class T> MyQueue<T>::MyQueue() {
    N = 0;
}

template <class T> int MyQueue<T>::size() {
    return N;
}

template <class T> bool MyQueue<T>::is_empty(){
    return 0 == N;
}

template <class T> void MyQueue<T>::enqueue(T t) {
    try {
        ml.insert(t);
    } catch (...) {
        cout<<"产生异常！！！"<<endl;
        exit(-1);
    }
}


template <class T> T MyQueue<T>::dequeue() {
    try {
        T tmp = ml.get(0);
        ml.remove(0);
        return tmp;
    } catch (...) {
        cout<<"产生异常！！！"<<endl;
        exit(-1);
    }
}
template <class T> void MyQueue<T>::show(){
    ml.show();
} 


int main(){
    MyQueue<int> ms;
    ms.show();
    ms.enqueue(0);
    ms.enqueue(1);
    ms.enqueue(2);
    ms.enqueue(3);
    ms.show();
    cout << "出队："<< ms.dequeue() << '\n' << endl;
    cout << "进队："<< ms.dequeue() << '\n' << endl;
    ms.show();
}
