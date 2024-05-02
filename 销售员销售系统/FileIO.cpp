// 将文本文件中特定月份的数据都存储在一个数组中
// 格式：arr[月份的天数][销售员代号][商品的代号]

// cout << "输入记录：//销售员的代号+每种产品的代号和销量" << endl;
// cout << "例如： A::1:1 2:2 3:3 4:4 5:5" << endl;

// 读入 ”salsesNote.txt“ 文件
#include <iostream>
#include <fstream>
#include "Sales.h"

using namespace std;

const int SALES_NUMBER = 5;
const int GOODS_NUMBER = 5;

Sales sales[SALES_NUMBER];
int arr[31][SALES_NUMBER][GOODS_NUMBER] = { 0 };

int fileRead(int arr[31][SALES_NUMBER][GOODS_NUMBER]);
int fileRead(Sales sales[]);


int fileRead(Sales sales[])
{
    cout << "正在读取文件132321\n";
	
	cout << "L28";
    ifstream fin;
    fin.open("salsesNote.txt", ios_base::in);

    long a = 0;
    fin >> a;
    cout << a;
    cout << 333;

    fin.close();
    cout << "读取文件成功！\n";
    
    return true;
}

int fileRead(int arr[31][SALES_NUMBER][GOODS_NUMBER])
{
    cout << "正在读取文件\n";
	
    long a = 0;
    ifstream fin("salsesNote.txt");
    // fin.open("salsesNote.txt", ios_base::in);


    fin >> a;
    cout << a << endl;

    fin.close();
    cout << "读取文件成功！\n";
    
    return true;
}