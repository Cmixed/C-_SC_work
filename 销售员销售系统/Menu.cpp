#ifndef MENU_CPP
#define MENU_CPP

#include <iostream>
#include "Sales.cpp"
#include "FileIO.cpp"

using namespace std;

static int month = 0;
static int option = 0;

void welcomeMenu(); // 欢迎菜单
void byeMenu();     // 退出菜单
void listOption();  // 列出所有的操作

int menuMonth();    // 返回 month
int menuOption();   // 返回 option
int optionCase(int option); // 调用相应 option 操作


int main(int argc, char const *argv[]) {
    welcomeMenu();
    month = menuMonth();
    option = menuOption();
    while (option)
    {
        optionCase(option);
        option = menuOption();
    }
    byeMenu();
    return 0;
}


// 返回 month 的值
int menuMonth()
{
    MONTH:// 月份值域 [1, 12]
    try
    {
        cout << "输入你想查询的月份：";
        cin >> month;
        if (cin.fail() )
        {
            throw -1; // 意外，非 int 类型 抛出 -1
        } else if((month > 12 || month < 1) ) 
        {
            throw "Error!!! 请输入正确的月份";
        }
    } catch (const char * s) 
    {
        std::cout << s << '\n';
        goto MONTH;
    } catch (int s) 
    {
        std::cout << "Error!!! 请输入一个整数\n";
        cin.clear(); cin.ignore(); // 用于设置 cin 对象状态 并 清除缓冲区
        goto MONTH;
    }

    return month;
}

// 返回 option 的值
int menuOption()
{
    OPTION:// 操作值域 [1, 5]
    try
    {
        cout << "输入你想进行的操作：\n" ;
        cin >> option;
        listOption();
        if (option == 0) {  return option; }    // 退出
        
        if(cin.fail() ) 
        {
            throw -1; // 意外，非 int 类型 抛出 -1
        } else if((option > 5 || option < 1) ) 
        {
            throw "Error!!! 请输入正确的操作选项代号";
        }
    } catch (const char * s) 
    {
        std::cout << s << '\n';
        goto OPTION;
    } catch (int & n) 
    {
        std::cout << "Error!!! 请输入一个整数\n";
        cin.clear();    cin.ignore();  // 用于设置 cin 对象状态 并 清除缓冲区
        goto OPTION;
    }

    return option;
}

// 调用相应 option 操作
int optionCase(int option)
{
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
        cout << "NO Related Option!!!" << endl;
        break;
    }

    return option;
}


// 欢迎菜单
void welcomeMenu()
{
    std::cout << "******销售员销售系统******" << endl;
}

// 退出菜单
void byeMenu()
{
    cout << "系统退出";
}     

// 列出选项
void listOption()
{
    cout << "1:F1" << endl;
    cout << "1:F1" << endl;
    cout << "1:F1" << endl;
    cout << "1:F1" << endl;
    cout << "1:F1" << endl;
    cout << "1:F1" << endl;
}

    
    // cout << "输入记录：//销售员的代号+每种产品的代号和销量" << endl;
    // cout << "例如： A::1:1 2:2 3:3 4:4 5:5" << endl;


#endif // !MENU_CPP
 