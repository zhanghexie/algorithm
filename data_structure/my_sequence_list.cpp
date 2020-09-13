/*
 * 顺序表
 * 采用一个数组存放数据，当数组长度不够用时会自动扩展。
 * */

#include <iostream>
#include <stdexcept>
#include "my_sequence_list.h"
using namespace std;

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
    try {
        ms.insert(6000,2);
    }catch (...) {
        cout<<"出现异常！！！"<<endl;
        ms.show();
    }
    ms.show();
    return 0;
}
