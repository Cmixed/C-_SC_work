#ifndef MENU_CPP
#define MENU_CPP

#include <iostream>
#include <cstdio>
#include "Sales.cpp"
#include "FileIO.cpp"

using namespace std;

static int month = 0;
static int option = 0;
static int lastOption = 0;

extern Sales sales[SALES_NUMBER];

void initSales(Sales sales[]);   // 初始化
void welcomeMenu(); // 欢迎菜单
void byeMenu();     // 退出菜单
void waitMenu();    // 等待菜单
void listOption();  // 列出所有的操作

int menuMonth();    // 返回 month
int menuOption();   // 返回 option
int optionCase(int option); // 调用相应 option 操作

void terminalClear(); // 清空控制台

int main(int argc, char const *argv[]) {

    initSales(sales);
    welcomeMenu();
STARTMONTH:
    month = menuMonth();

    // if (!fileRead(arr, month))   { byeMenu(); goto QUIT;}

    if (!fileRead(sales, month))   { byeMenu(); goto QUIT;}

    option = menuOption();      // 初始 option
    
    while (option)
    {
        optionCase(option);     // 调用相应 option 操作
        lastOption = option;    // 初始化 lastoption
        fileWrite(lastOption);
        waitMenu();             // 等待
        option = menuOption();  // 更新 option

    }
    byeMenu();

QUIT:

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
    } catch (int n) 
    {
        std::cout << "Error!!! 请输入一个整数\n";
        cin.clear(); cin.ignore(1024, '\n'); // 用于设置 cin 对象状态 并 清除缓冲区
        goto MONTH;
    }

    return month;
}

// 返回 option 的值
int menuOption()
{
    listOption();

OPTION:// 操作值域 [0, 5]
    try
    {
        cout << "输入你想进行的操作：" ;
        cin >> option;
        if(cin.fail() ) 
        {
            throw -1; // 意外，非 int 类型 抛出 -1
        } else if((option > 5 || option < 0) ) 
        {
            throw "Error!!! 请输入正确的操作选项代号";
        }
    } catch (const char * s) 
    {
        std::cout << s << '\n';
        goto OPTION;
    } catch (int n) 
    {
        std::cout << "Error!!! 请输入一个整数\n";
        cin.clear();    cin.ignore(1024, '\n');  // 用于设置 cin 对象状态 并 清除缓冲区
        goto OPTION;
    }

    return option;
}

// 调用相应 option 操作
int optionCase(int option)
{
    switch (option)
    {
    case 0:         // 没有实际作用
        byeMenu();
        break;
    case 1:
        caculatePrePeopleSales(sales);
        break;
    case 2:
        sortSales(sales);
        break;
    case 3:
        sortAll(sales);
        break;
    case 4:
        outLable(sales);
        break;
    case 5:
        funcLastOption(lastOption);
        break;
    default:
        cout << "NO Related Option!!!" << endl;
        break;
    }

    return option;
}

//初始化
void initSales(Sales sales[])
{
    for (int i = 0; i < SALES_NUMBER; i++)
    {
        sales[i] = Sales(i, 0, 0, 0, 0, 0);
    }
}

// 欢迎菜单
void welcomeMenu()
{
    static int flag = 0;
    std::cout << "Application:销售员销售系统\n" << endl;
    if (flag)
    {
        cout << "!当前查询月份：" << month << endl;
    }

    flag = 1;
    
}

void terminalClear()
{
    system("cls");
    welcomeMenu();
    // cout << "\033[2J\033[H";
}

void waitMenu()
{
    cout << endl;
    cout << "按回车键以进行下一项操作";
    cin.get(); cin.get();
}

// 退出菜单
void byeMenu()
{
    terminalClear();
    cout << "\n系统退出";
}     

// 列出选项
void listOption()
{
    terminalClear();

    ios_base::fmtflags old = cout.setf(ios::left, ios::adjustfield);    // 调整为左对齐

    cout << endl;
    cout.width(40);
    cout << "0)退出系统                  1)计算某个月每个人每种产品的销售量\n";
    cout.width(40);
    cout << "2)按销售量对销售员进行排序  3)统计每种产品的总销售量（高到低）\n";
    cout.width(40);
    cout << "4)输出统计报表              5)输出上一个操作\n";
    cout << endl;

    cout.setf(old, ios::adjustfield); // 恢复格式
}




#endif // !MENU_CPP
 