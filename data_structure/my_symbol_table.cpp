# include "my_symbol_table.h"
# include <string>
using namespace std;

int main(){
    MySymbolTable<string, string> ms;
    ms.show();
    
    cout<<"测试插入"<<endl;
    ms.insert("name", "zhang");
    ms.insert("age", "22");
    ms.insert("sex", "man");
    ms.show();
    ms.insert("name", "zhang");
    ms.show();

    cout<<"测试查找"<<endl;
    cout<<"name is "<<ms.get("name")<<endl;
    try{
        cout<<"class is "<<ms.get("class")<<endl;
    }catch(...){
        cout<<"出现异常"<<endl;
    }
    
    cout<<"测试删除"<<endl;
    ms.remove("name");
    ms.show();
    return 0;
}
