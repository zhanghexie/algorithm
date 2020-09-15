#include <iostream>
#include "my_binary_tree.h"
#include <string>
using namespace std;

int main(){
    MyBinaryTree<int, string> mt;
    mt.put(7,"xiaoming");
    //mt.put(5,"daming");
    //mt.put(9,"xiaozhong");
    //mt.put(3,"xiaolu");
    //mt.put(8,"honghong");
    //cout << mt.get(3) << endl;
    //cout << mt.get(5) << endl;
    //cout << mt.get(7) << endl;
    return 0;
}


