// 将文本文件中特定月份的数据都存储在一个对象数组中

// cout << "输入记录：月份+销售员的代号+每种产品的代号和销量" << endl;
// cout << "例如：  7A  1 1 2 2 3 3 4 4 5 5

// 读入 ”data.txt“ 文件

#include <iostream>
#include <fstream>
#include <cstdio>
#include "Sales.cpp"

using namespace std;

const int SALES_NUMBER = 5;

Sales sales[SALES_NUMBER];

int fileRead(Sales sales[], int month);

int fileRead(Sales sales[], int month)
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
    


    for (int i = 0; i < SALES_NUMBER; i++)
    {
        cout << "测试输出：\n";
        sales[i].display();
        cout << "测试输出结束：\n";
    }
    
    fin.close();
    cout << "读取文件成功！\n";
    
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