// 主菜单文件，负责所有终端显示，面向客户
// Main 函数所在文件

#ifndef MENU_CPP
#define MENU_CPP

#include <iostream>
#include <cstdio>  
#include "Sales.cpp"    // Sales 相应操作
#include "FileIO.cpp"   // 文件输入输出
#include "Color.cpp"    // 控制台相关

using namespace std;
using namespace color;  // Color.cpp namespace

// 全局变量
static int month = 0;
static int option = 0;
static int lastOption = 0;

// 外部变量
extern Sales sales[SALES_NUMBER];   // 来自 FileIO.cpp
extern const int OPTION_NUMBER;     // 来自 Sales.cpp

// 函数列表
// 菜单相关函数
void lableMenu(bool flagQuit, bool flagEnterNew); // 标题菜单,参数1 0 为退出， 1为正常, 参数2 0 操作界面， 1 选项界面
void byeMenu();     // 退出菜单
void waitMenu();    // 等待菜单
void listMenu();  // 列出所有的操作
void clearMenu(bool flagEnterNew);    // 清空菜单
// 用户输入相关处理函数
int menuMonth();    // 返回 month
int menuOption();   // 返回 option
int optionCase(int option); // 调用相应 option 操作


// Main 函数 程序起点

int main(int argc, char const *argv[]) 
{

    initSales(sales);   // 初始化
    lableMenu(0, 0);      // 初始化菜单栏

STARTMONTH:

    month = menuMonth();    // 读入月份

    // 文件读入
    if (!fileRead(sales, month))   { byeMenu(); goto QUIT;}

    option = menuOption();      // 初始 option

    // 判断是否切换月份
    if (6 == option) { goto STARTMONTH; }

    while (option)
    {
        clearMenu(0);    // 清空终端

        lastOption =  optionCase(option);     // 调用相应 option 操作 并 初始化 lastoption

        fileWrite(lastOption, month); // 将刚才的操作存入文件

        waitMenu();             // 等待
    
        option = menuOption();  // 更新 option

        // 判断是否切换月份
        if (6 == option) { goto STARTMONTH; }

    }

    byeMenu();  // 结束菜单

QUIT:

    return 0;
}

// 返回 month 的值
int menuMonth()
{

MONTH:// 月份值域 [1, 12]
    
    colorGreen();

    // try catch 异常处理
    try
    {
        cout << endl << "输入你想查询的月份：";
        cin >> month;

        if (cin.fail() )
        {
            throw -1; // 异常，非 int 类型 抛出 -1
        } else if ((month > 12 || month < 1) ) 
        {
            throw -2; // 异常，不在范围内 抛出 -2
        }

    } catch (int n) // 处理相应的异常
    {
        colorRed();

        if (-1 == n)    // 非 int 类型 抛出 -1
        {
            std::cout << "Error!!! 请输入一个整数\n";
        } else if (-2 == n) // 不在范围内 抛出 -2
        {
            std::cout << "Error!!! 请输入正确的月份" << '\n';
        }

        // 设置 cin 对象状态 并 清除缓冲区
        cin.clear(); cin.ignore(1024, '\n'); 

        colorDefault();

        goto MONTH;
    }

    colorDefault();

    return month;
}

// 返回 option 的值
int menuOption()
{
    listMenu();

OPTION:// 操作代码值域 [0, 6]

    colorGreen();

    try
    {
        cout << endl << "输入你想进行的操作：" ;
        cin >> option;

        if (cin.fail() ) 
        {
            throw -1;   // 异常，非 int 类型 抛出 -1
        } else if ((option > OPTION_NUMBER || option < 0) ) 
        {
            throw -2; // 异常，不在范围内 抛出 -2
        }
    } catch (int n) // 处理相应的异常
    {
        colorRed();

        if (-1 == n)    // 非 int 类型 抛出 -1
        {
            std::cout << "Error!!! 请输入一个整数\n";
        } else if (-2 == n) // 不在范围内 抛出 -2
        {
            std::cout << "Error!!! 请输入正确的操作选项代号" << '\n';
        }
        
        // 设置 cin 对象状态 并 清除缓冲区
        cin.clear();    cin.ignore(1024, '\n');  

        colorDefault();

        goto OPTION;
    }

    colorDefault();

    return option;
}

// 调用相应 option 操作
int optionCase(int option)
{
    switch (option)
    {
    case 0:
        byeMenu();
        break;
    case 1:
        caculatePrePeopleSales(sales);
        break;
    case 2:
        sortSales(sales);
        break;
    case 3:
        sortGoods(sales);
        break;
    case 4:
        outLable(sales);
        break;
    case 5:
        funcHistoryOption(lastOption);
        break;
    case 6:
        // 切换操作月份，使用 goto 在 main 中实现
        cout << "Impossible!!!";    
        break;
    default:
        cout << "NO Related Option!!!" << endl;
        // 防止意外
        break;
    }

    return option;
}


// 标题菜单,参数 0 为退出， 1为正常
void lableMenu(bool flagQuit, bool flagEnterNew)
{
    // flagQuit == 1 时，状态为 退出
    // flagQuit == 0 时，状态正常

    // flagEnterNew == 1 时， 输入新的操作
    // flagEnterNew == 0 时， 没输入新的操作

    colorPurple();  // 标题紫色

    std::cout << "Application:销售员销售系统\n" << endl;

    if (!flagQuit)  // 正常状态
    {
        if (month)
        {
            colorCyan();    // 青色

            cout << "# 当前查询月份：" << month << endl;
            
            if (option) // 添加操作选项状态
            {
                // 操作选项状态 option 界面 还是 选项吧执行界面
                if (!flagEnterNew)
                {
                    cout << "# 当前操作选项：" << option;
                } else
                {
                    cout << "& 刚才操作选项：" << option;
                }
                
                switchOptionText(option);

            }
            else
            {
                cout << "? 当前暂无操作选项" << endl;
            }
            
        } else
        {
            colorBlue();
            cout << "? 当前暂无查询月份" << endl;
        }
    } else
    {
        colorRed();
        cout << "! 最后查询月份：" << month << endl;
        cout << "! 最后操作选项：" << lastOption;

        switchOptionText(lastOption);
        
    }

    // 恢复 flagEnterNew 变量的值

    if (flagEnterNew)
    {
        flagEnterNew = 0;        
    }


    colorDefault();
    
}

void clearMenu(bool flagEnterNew)
{
    system("cls");
    
    lableMenu(0, flagEnterNew);   // 传递参数 0， falgQuit = 0，状态栏状态正常

    // cout << "\033[2J\033[H"; for liunx to use
}

void waitMenu()
{
    colorGreen();

    cout << endl << "按回车键以进行下一项操作";
    
    cin.get(); cin.get();

    colorDefault();
}

// 退出菜单
void byeMenu()
{

    system("cls");  // 清空终端

    lableMenu(1, 0);   // 传递参数 1， falgQuit = 1，状态栏状态为退出

    colorGreen();

    cout << "\n系统退出\n";
    cout << "\n欢迎下次使用(按回车键退出)";

    cin.get(); cin.get();

    colorDefault();
}     

// 列出选项
void listMenu()
{
    clearMenu(1);    // 清空终端

    colorYellow();

    ios_base::fmtflags old = cout.setf(ios::left, ios::adjustfield);    // 调整为左对齐

    cout << endl;
    cout.width(40);
    cout << "0)退出系统                  1)计算某个月每个人每种产品的销售量\n";
    cout.width(40);
    cout << "2)按销售量对销售员进行排序  3)统计每种产品的总销售量（高到低）\n";
    cout.width(40);
    cout << "4)输出统计报表              5)获取更多历史操作\n";
    cout.width(40);
    cout << "6)更改操作月份\n";
    cout << endl;

    cout.setf(old, ios::adjustfield); // 恢复格式

    colorDefault();
}


#endif // !MENU_CPP 