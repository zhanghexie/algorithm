/*
 * 顺序表
 * 采用一个数组存放数据，当数组长度不够用时会自动扩展。
 * */

#include <iostream>
#include <stdexcept>
#include "my_sequence_list.h"
#define MAX_CAP 65536
using namespace std;

template<class T>
MySequenceList<T>::MySequenceList(){
    N = 0;
    capacity = 64;
    elements = new T[capacity];
}

template<class T>
void MySequenceList<T>::clear(){
    N=0;
    delete []elements;
    capacity = 64;
    elements = new T[capacity];

}

template<class T>
bool MySequenceList<T>::is_empty(){
    return 0 == N;
}

template<class T>
int MySequenceList<T>::length(){
    return N;
}

template<class T>
T MySequenceList<T>::get(int i){
    return elements[i];
}

template<class T>
void MySequenceList<T>::insert(T t){
    if(N<capacity){
        elements[N++] = t;
        return;
    }
    if(N>=capacity && capacity<MAX_CAP){
        capacity = capacity*2 > MAX_CAP ? MAX_CAP : capacity*2;
        T *temp = new T[capacity];
        for(int i=0; i<N; i++){
            temp[i] = elements[i];
        }
        delete []elements;
        elements = temp;
        elements[N++]=t;
    }else{
        cout << "数组越界" << endl;
        throw "数组越界";
    }
}

template<class T>
void MySequenceList<T>::insert(int i, T t){
    // 判断插入的位置是否合法
    if(i>N){
        cout<<"插入位置超过最后一位！！！"<<endl;
        throw "插入位置超过最后一位！！！";
        return;
    }
    // 如果有剩余空间直接插入。
    if(N < capacity){
        //进行插入
        for(int j=N++; j>i; j--){
            elements[j] = elements[j-1];
        }
        elements[i] = t;
    }else if(capacity>=MAX_CAP){
        cout << "没有容量了" << endl;
        throw "没有容量了";
        return;
    }else{
        capacity = capacity*2 > MAX_CAP ? MAX_CAP : capacity*2;
        T *temp = new T[capacity];
        for(int j=0; j<i; j++)temp[j] = elements[j];
        temp[i] = t;
        for(int j = i+1; j < N+1; j++) temp[j] = elements[j-1];
        delete []elements;
        elements = temp;
        N++;
    }
}

template<class T>
void MySequenceList<T>::remove(int i){
    // 需要缩小尺寸，建立新数组的同时删除旧的。
    if(N-1 <= capacity/2){
        capacity/=2;
        T *temp = new T[capacity/2];
        int j = 0;
        while(j<i){
            temp[j] = elements[j];	
            j++;
        }
        while(j<N-1){
            temp[j] = elements[j+1];
            j++;
        }
        delete [] elements;
        elements = temp;
        N--;
        // 不需要缩小就直接删除。
    }else{
        for(int j = i; j < N-1; j++){
            elements[j] = elements[j+1];
        }
        N--;
    }
}

template<class T>
int MySequenceList<T>::index_of(T t){
    for(int i=0; i < N; i++){
        if(elements[i]==t) return i;
    }
    cout<<"找不到您想要的元素"<<endl;
    return -1;
}

template<class T>
void MySequenceList<T>::show(){
    cout<<"以用长度："<<N<<endl;
    cout<<"实际长度："<<capacity<<endl;
    cout<<"数据如下：";
    for(int j = 0; j < N; j++){
        cout<<elements[j]<<" ";
    }
    cout<<endl;
}

int main(){
    MySequenceList<int> ms;
    ms.show();
    cout<<"插入64个数"<<endl;
    for(int i = 0; i < 64; i++){
        ms.insert(i);
    }
    ms.show();
    cout<<"第一个2在："<<ms.get(2)<<endl;
    ms.insert(0,1);
    cout<<"再插入1个数"<<endl;
    ms.show();
    cout<<"删除1个数"<<endl;
    ms.remove(0);
    ms.show();
    ms.insert(65537,2);
    return 0;
}
