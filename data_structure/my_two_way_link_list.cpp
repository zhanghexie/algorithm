/*
 * 双向列表
 * 采用一个个相连的节点存放数据，在双项列表中一个结点指向前后两个节点指针。
 * */

#include <ctime>
#include <iostream>
#include "my_two_way_link_list.h"
using namespace std;

int main(){
    MyTwoWayLinkList<int> ml;
    ml.show();

    for (int i = 0; i < 64; i++) {
        ml.insert(i);
    }
    ml.show();
    
    cout << "第一个2在：" << ml.get(2) << endl;
    
    cout<<"在插入0处插入"<<endl;
    ml.insert(0, 1);
    ml.show();
    
    cout<<"在插入中间插入"<<endl;
    ml.insert(2, 0);
    ml.show();

    cout<<"在末尾插入"<<endl;
    ml.insert(1);
    ml.show();
   
    cout<<"在末尾删除"<<endl;
    ml.remove();
    ml.show();

    cout<<"在中间删除"<<endl;
    ml.remove(2);
    ml.show();

    cout<<"在0处删除"<<endl;
    ml.remove(0);
    ml.show();

    try{ml.insert(65537, 2);}catch(...){
        cout<<"出现异常。"<<endl;
    }
    cout<<"执行完毕"<<endl;
    return 0;
}
