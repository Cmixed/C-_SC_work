#ifndef MENU_CPP
#define MENU_CPP

#include <iostream>
#include <cstdio>
#include "Sales.cpp"
#include "FileIO.cpp"

using namespace std;

// 全局变量
static int month = 0;
static int option = 0;
static int lastOption = 0;
static int flagQuit = 0;    // 退出标志 由 byeMenu()设置

// 外部变量
extern Sales sales[SALES_NUMBER];   // 来自 FileIO.cpp

// 函数
// 准备工作
void initSales(Sales sales[]);   // 初始化
// 菜单相关
void lableMenu(); // 标题菜单
void byeMenu();     // 退出菜单
void waitMenu();    // 等待菜单
void listMenu();  // 列出所有的操作
// 控制台相关
void terminalClear(); // 清空控制台
void colorDefault(); // 字体默认颜色
void colorRed();    // 字体变红
void colorGreen();  // 字体变绿
void colorYellow(); // 字体变黄
void colorBlue();   // 字体变蓝
void colorPurple(); // 字体变紫
void colorCyan();   // 字体变青
void colorWhite();  // 字体变白
// 操作相关
int menuMonth();    // 返回 month
int menuOption();   // 返回 option
int optionCase(int option); // 调用相应 option 操作



int main(int argc, char const *argv[]) {

    initSales(sales);   // 初始化
    lableMenu();      // 欢迎

STARTMONTH:
    month = menuMonth();

    // if (!fileRead(arr, month))   { byeMenu(); goto QUIT;}

    if (!fileRead(sales, month))   { byeMenu(); goto QUIT;}

    option = menuOption();      // 初始 option

    if (option == 6)    // 切换月份
    {
        goto STARTMONTH;
    }

    while (option)
    {
        optionCase(option);     // 调用相应 option 操作
        lastOption = option;    // 初始化 lastoption
        fileWrite(lastOption, month);
        waitMenu();             // 等待
        option = menuOption();  // 更新 option

        if (option == 6)    // 切换月份
        {
            goto STARTMONTH;
        }
    }
    byeMenu();

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
        cout << endl;
        cout << "输入你想查询的月份：";
        cin >> month;
        if (cin.fail() )
        {
            throw -1; // 意外，非 int 类型 抛出 -1
        } else if((month > 12 || month < 1) ) 
        {
            throw "Error!!! 请输入正确的月份"; // 抛出 字符串
        }
    } catch (const char * s) // 处理字符串
    {
        colorRed();
        std::cout << s << '\n';
        colorDefault();

        goto MONTH;
    } catch (int n) // 处理 -1
    {
        colorRed();
        std::cout << "Error!!! 请输入一个整数\n";
        colorDefault();
        cin.clear(); cin.ignore(1024, '\n'); // 用于设置 cin 对象状态 并 清除缓冲区

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
        cout << endl;
        cout << "输入你想进行的操作：" ;
        cin >> option;
        if(cin.fail() ) 
        {
            throw -1; // 意外，非 int 类型 抛出 -1
        } else if((option > 6 || option < 0) ) 
        {
            throw "Error!!! 请输入正确的操作选项代号";
        }
    } catch (const char * s) 
    {
        colorRed();
        std::cout << s << '\n';
        colorDefault();

        goto OPTION;
    } catch (int n) 
    {
        colorRed();
        std::cout << "Error!!! 请输入一个整数\n";
        colorDefault();
        cin.clear();    cin.ignore(1024, '\n');  // 用于设置 cin 对象状态 并 清除缓冲区

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
        sortAll(sales);
        break;
    case 4:
        outLable(sales);
        break;
    case 5:
        funcLastOption(lastOption);
        break;
    case 6:
        cout << "Impossible!!!";
        // 切换操作月份，使用 goto 在 main 中实现
        break;
    default:
        cout << "NO Related Option!!!" << endl;
        break;
    }

    return option;
}

// 初始化
void initSales(Sales sales[])
{
    for (int i = 0; i < SALES_NUMBER; i++)
    {
        sales[i] = Sales(i, 0, 0, 0, 0, 0);
    }
}

// 标题菜单
void lableMenu()
{
    static int flagFirst = 0;

    colorPurple();
    std::cout << "Application:销售员销售系统\n" << endl;

    if (flagFirst && !flagQuit)
    {
        colorCyan();
        cout << "# 当前查询月份：" << month << endl;
    } else if (flagQuit)
    {
        colorRed();
        cout << "! 最后查询月份：" << month << endl;
    }

    colorDefault();
    flagFirst = 1;
    
}

void terminalClear()
{
    system("cls");
    lableMenu();

    // cout << "\033[2J\033[H"; for liunx to use
}

void waitMenu()
{
    colorGreen();
    cout << endl;
    cout << "按回车键以进行下一项操作";
    colorDefault();
    cin.get(); cin.get();
}

// 退出菜单
void byeMenu()
{
    flagQuit = 1;   // 设置退出标志为 1

    terminalClear();

    colorPurple();

    cout << "\n系统退出" << endl;
    cout << "\n欢迎下次使用" << endl;

    colorDefault();
}     

// 列出选项
void listMenu()
{
    terminalClear();

    colorYellow();

    ios_base::fmtflags old = cout.setf(ios::left, ios::adjustfield);    // 调整为左对齐

    cout << endl;
    cout.width(40);
    cout << "0)退出系统                  1)计算某个月每个人每种产品的销售量\n";
    cout.width(40);
    cout << "2)按销售量对销售员进行排序  3)统计每种产品的总销售量（高到低）\n";
    cout.width(40);
    cout << "4)输出统计报表              5)输出上一个操作\n";
    cout.width(40);
    cout << "6)更改操作月份\n";
    cout << endl;

    cout.setf(old, ios::adjustfield); // 恢复格式

    colorDefault();
}

// 字体默认颜色
void colorDefault()
{
    cout << "\033[0m";
}

// 字体变红
void colorRed()
{
    cout << "\033[31m";
}

// 字体变绿
void colorGreen()
{
    cout << "\033[32m";
}

// 字体变黄
void colorYellow()
{
    cout << "\033[33m";
}

// 字体变蓝
void colorBlue()
{
    cout << "\033[34m";
}

// 字体变紫
void colorPurple()
{
    cout << "\033[35m";
} 

// 字体变青
void colorCyan()
{
    cout << "\033[36m";
}

// 字体变白
void colorWhite()
{
    cout << "\033[37m";
}


#endif // !MENU_CPP
 