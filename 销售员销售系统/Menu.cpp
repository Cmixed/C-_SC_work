#ifndef MENU_CPP
#define MENU_CPP

#include <iostream>
#include "Sales.cpp"
#include "Menu.cpp"
#include "FileIO.cpp"

using namespace std;

void Main_Menu(); // 主菜单

int main(int argc, char const *argv[]) {
    Main_Menu();

    return 0;
}


// 主菜单
void Main_Menu()
{
    static int month = 0; // 操作的月份全局变量
    int option = 0; // 操作的标记变量

    cout << "******销售员销售系统******" << endl;


MONTH:// 月份值域 [1, 12]
    try
    {
        cout << "输入你想查询的月份：";
        cin >> month;
        if((month > 12 || month < 1) ) {
            
            throw "Error!!! 请输入正确的月份";
        }
    } catch(const char * s) {
        std::cerr << s << '\n';
        if (cin.fail() && !cin.eof() )
        {
            cin.clear();
            while ( cin.get() != '\n' )
            {
                continue;
            }
        }
        else
        {
            cout << "I cannot go on!\n";
            exit(1);
        }
        // cin.ignore(); cin.clear(); cin.sync(); // 防止数据类型不对引发的异常
        goto MONTH;
    }
    
OPTION:// 操作值域 [1, 5]
    try
    {
        cout << "输入你想进行的操作：" ;
        cin >> option;
        if(cin.fail() ) {
            // cin.clear();    cin.ignore();
            throw -1;
        } else if((option > 5 || option < 1) ) {
            throw "Error!!! 请输入正确的操作代号";
        }
    } catch(const char * s) {
        std::cerr << s << '\n';
        goto OPTION;
    } catch(int & n) {

        std::cerr << n << '\n';
        cin.clear();    cin.ignore();
        goto OPTION;
    }
    
// Switch 进行菜单选择
    switch (option)
    {
    case 1:
        Function1();
        break;
    case 2:
        Function1();
        break;
    case 3:
        Function1();
        break;
    case 4:
        Function1();
        break;
    case 5:
        Function1();
        break;
    
    default:
        cout << "NO OPtion!!!" << endl;
        break;
    }
    
    cout << "输入记录：//销售员的代号+每种产品的代号和销量" << endl;
    cout << "例如： A::1:1 2:2 3:3 4:4 5:5" << endl;
}

#endif // !MENU_CPP
 