// 将文本文件中特定月份的数据都存储在一个对象数组中

// cout << "输入记录：月份+销售员的代号+每种产品的代号和销量" << endl;
// cout << "例如：  7A  1 1 2 2 3 3 4 4 5 5

// 读入 ”data.txt“ 文件
// 存入 “oprion.txt” 文件

#include <iostream>
#include <fstream>
#include <chrono>
#include <iomanip>
#include "Sales.cpp"    // Sales 相关操作

// 全局变量
Sales sales[SALES_NUMBER];

// 函数列表
int fileRead(Sales sales[], int month); // 文件读入
int fileWrite(int option, int month);   // 文件写入

int fileRead(Sales sales[], int month)
{
    using namespace std;

    // 清零
    for (int i = 0; i < SALES_NUMBER; i++)
    {
        sales[i] = Sales(i, 0, 0, 0, 0, 0);
    }

    cout << endl;
    cout << "正在读取文件。\n";
	
    // FILE * fp = fopen("data.txt", "r");
    ifstream fin("data.txt", ios_base::in | ios_base::binary);

    char SalseOrder;
    int temmonth, a, as, b, bs, c, cs, d, ds, e, es;

    for (int i = 0; i < 31; i++)
    {
        fin >> temmonth >> SalseOrder >> a >> as
            >> b >> bs >> c >> cs >> d >> ds >> e >> es;

        if (temmonth < month)
        {
            --i; continue;
        } else if (temmonth > month)
        {
            break;
        }
        
        int order = (int)(SalseOrder - 'A'); // 找到相应的销售员序号
        // sales[i] = Sales(as, bs, cs, ds, es);
        sales[order].caculateSales(as, bs, cs, ds, es);
    }
    
    // 更新 sum_成员, 即所有的货物销售量总和
    for (int i = 0; i < SALES_NUMBER; i++)
    {
        sales[i].sum();
    }
    

// 测试用，输出每个人的每个销售量
    // for (int i = 0; i < SALES_NUMBER; i++)
    // {
    //     cout << "测试输出：\n";
    //     sales[i].display();
    //     cout << "测试输出结束：\n";
    //     cin.get();
    // }
    
    fin.close();
    cout << "读取文件成功！\n";
    
    return true;
}

int fileWrite(int option, int month)
{
    using namespace std;
    static int lineNumber = 1;

    ofstream fout("option.txt", ios_base::out | ios_base::app);

    // 获取当前时间点
    auto now = std::chrono::system_clock::now();
    // 将时间点转换为time_t以便进一步转换为本地时间
    std::time_t now_time = std::chrono::system_clock::to_time_t(now);
    // 将time_t转换为tm结构以便打印
    std::tm* now_tm = std::localtime(&now_time);

    if (lineNumber == 1)    // 本次运行的第一次
    {
        fout << endl;
        fout << std::put_time(now_tm, "%Y-%m-%d %H:%M:%S") << endl;
    }

    // 打印格式化的时间
    ios_base::fmtflags old = fout.setf(ios::left, ios::adjustfield);

    fout << setw(4) << lineNumber << " : " ;
    fout << std::put_time(now_tm, "%Y-%m-%d %H:%M:%S") << ' '   << "  月份：" << setw(4) << month <<  "  操作代号：" << option;

    switch (option) // 添加操作代号注释
    {
    case 0:     // !!!NO USE
        break;
    case 1:
        fout << " ：计算某个月每个人每种产品的销售量\n";
        break;
    case 2:
        fout << " ：按销售量对销售员进行排序\n";
        break;
    case 3:
        fout << " ：统计每种产品的总销售量（高到低）\n";
        break;
    case 4:
        fout << " ：输出统计报表\n";
        break;
    case 5:
        fout << " ：获取更多历史操作\n";
        break;
    case 6:
        break;      // !!!NO USE
    default:
        break;
    }

    ++lineNumber;

    fout.setf(old, ios::adjustfield);
    fout.close();
    return true;
}


/* 旧的实现
int fileRead(int arr[31][SALES_NUMBER][GOODS_NUMBER], int month)
{
    cout << endl;
    cout << "正在读取文件。\n";
	
    // FILE * fp = fopen("data.txt", "r");
    ifstream fin("data.txt", ios_base::in | ios_base::binary);

    char SalseOrder;
    int temmonth, a, as, b, bs, c, cs, d, ds, e, es;

    for (int i = 0; i < 31; i++)
    {
        fin >> temmonth >> SalseOrder >> a >> as
            >> b >> bs >> c >> cs >> d >> ds >> e >> es;

        if (temmonth == month)
        {
            cout << SalseOrder;
        } else if (temmonth < month)
        {
            --i; continue;
        } else if (temmonth > month)
        {
            break;
        }

    }
    
    

    fin.close();
    cout << "读取文件成功！\n";
    
    return true;
}
*/