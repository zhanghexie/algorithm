/*
 * 栈
 * 后进先出的数据结构。
 * */

#include <iostream>
#include <stdexcept>
#include "my_stack.h"
#define MAX_CAP 65536
using namespace std;


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
