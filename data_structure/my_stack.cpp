/*
 * 栈
 * 后进先出的数据结构。
 * */

#include <iostream>
#include <stdexcept>
#include "my_stack.h"
#define MAX_CAP 65536
using namespace std;

template <class T> MyStack<T>::MyStack() {
    N = 0;
    elements = new T[MAX_CAP];
}

template <class T> int MyStack<T>::size() {
    return N;
}

template <class T> bool MyStack<T>::is_empty(){
    return 0 == N;
}

template <class T> void MyStack<T>::push(T t) {
    if(N < MAX_CAP){
        elements[N++] = t;
    }else{
        cout << "[异常]栈已满！！！" << endl;
        throw "[异常]栈已满！！！";
        return;
    }
}

template <class T> T MyStack<T>::pop() {
    if(N > 0){
        return elements[--N];
    }else{
        cout << "[异常]栈为空！！！" << endl;
        throw "[异常]栈为空！！！";
        return -1;
    }
}
template <class T> void MyStack<T>::show() {
    cout << "栈容量上限：" << MAX_CAP << endl;
    cout << "栈已用大小：" << N << endl;
    if(N==0){
        cout << "栈为空。\n" << endl;
        return;
    }
    cout << "栈内容如下：" << endl;
    for(int i = 0; i < N; i++){
        cout << elements[N-1-i] << endl; 
        cout << "^" << endl;
    }
    cout<<"栈底\n"<<endl;
}

int main(){
    MyStack<int> ms;
    ms.show();
    ms.push(0);
    ms.push(1);
    ms.push(2);
    ms.push(3);
    ms.show();
    cout << "弹出："<< ms.pop() << '\n' << endl;
    cout << "弹出："<< ms.pop() << '\n' << endl;
    ms.show();
}
