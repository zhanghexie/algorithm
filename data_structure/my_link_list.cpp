/*
 * 单向列表
 * 采用一个个相连的节点存放数据，在单项列表中一个结点只有一个指向下一节点的指针。
 * */

#include "my_link_list.h"
using namespace std;


int main(){
    MyLinkList<int> ml;
    ml.show();

    for (int i = 0; i < 64; i++) {
        ml.insert(i);
    }
    ml.show();
    
    cout << "第一个2的位置是：" << ml.get(2) << '\n' << endl;
    
    cout<<"在0处插入"<<endl;
    ml.insert(0, 666);
    ml.show();
    
    cout<<"在中间插入"<<endl;
    ml.insert(2, 666);
    ml.show();

    cout<<"在末尾插入"<<endl;
    ml.insert(666);
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
