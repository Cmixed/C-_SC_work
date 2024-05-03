#ifndef SALES_CPP
#define SALES_CPP

#include <iostream>
using namespace std;

class Sales
{
private:
    /* data */
    char order_ = 'N';
    int arr[5] = { 0 }; 
public:
    Sales() = default;
    Sales(int goodOrder, int goodMumber);
    Sales(int as, int bs, int cs, int ds, int es) 
    {
        arr[0] += as;    arr[1] += bs;
        arr[2] += cs;    arr[3] += ds;
        arr[4] += es;
    }
    Sales(int SalseOrder, int as, int bs, int cs, int ds, int es) 
    {
        char order = (char)(SalseOrder + 'A');
        order_ = order;
        arr[0] = as;    arr[1] = bs;
        arr[2] = cs;    arr[3] = ds;
        arr[4] = es;
    }
    ~Sales();

    void order(char order);
    void display();
    void caculateSales(int as, int bs, int cs, int ds, int es);   // 累加计算

    friend int funcLastOption(int lastOption); //（0） 输出上一个操作
    friend int caculatePrePeopleSales(Sales sales[]); //（1）	计算某个月每个人每种产品的销售量
    friend int sortSales(Sales sales[]); //（2）	按销售量对销售员进行排序，输出排序结果；
    friend int sortAll(Sales sales[]); //（3）	统计每种产品的总销售量，对这些产品按从高到低的顺序，输出排序结果（需输出产品的代号和销售量）；
    friend int outLable(Sales sales[]); //（4）	输出统计报表
};

// 构造函数：货物序号，货物数量
Sales::Sales(int goodOrder, int goodMumber)
{
    // 序号比数组的序号大一，所以 arr[]参数要减一
    arr[--goodOrder] = goodMumber;
}

Sales::~Sales()
{
    
}

void Sales::order(char order)
{
    order_ = order;
}

void Sales::display()
{
    cout << "以下为售货员 " << order_ << " 的各物品售货量" << endl;
    cout << "货物1的销售量为: " << arr[0] << endl; 
    cout << "货物2的销售量为: " << arr[1] << endl; 
    cout << "货物3的销售量为: " << arr[2] << endl; 
    cout << "货物4的销售量为: " << arr[3] << endl; 
    cout << "货物5的销售量为: " << arr[4] << endl; 
}


int funcLastOption(int lastOption) {
    std::cout << "Last option is "<< lastOption << std::endl;
    return lastOption;
}

//（1）	计算某个月每个人每种产品的销售量
int caculatePrePeopleSales(Sales sales[]) 
{
    std::cout << "Function: " << "caculatePrePeopleSales" << std::endl;
    return 0;
}
//（2）	按销售量对销售员进行排序，输出排序结果；
int sortSales(Sales sales[]) 
{
    std::cout << "Function: " << "sortSales" << std::endl;
    return 0;
}
//（3）	统计每种产品的总销售量，对这些产品按从高到低的顺序，输出排序结果（需输出产品的代号和销售量）；
int sortAll(Sales sales[])
{
    std::cout << "Function: " << "sortAll" << std::endl;
    return 0;
}
//（4）	输出统计报表
int outLable(Sales sales[])
{
    std::cout << "Function: " << "outLable" << std::endl;
    return 0;
}

void Sales::caculateSales(int as, int bs, int cs, int ds, int es)
{
    arr[0] += as;   arr[1] += bs;
    arr[2] += cs;   arr[3] += ds;
    arr[4] += es;
}

#endif // !SALES_CPP