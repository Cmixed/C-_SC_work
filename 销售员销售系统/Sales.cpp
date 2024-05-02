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
        arr[0] = as;    arr[1] = bs;
        arr[2] = cs;    arr[3] = ds;
        arr[4] = es;
    }
    ~Sales();

    void order(char order);
    void display();

    friend int funcLastOption(int lastOption); //（0） 输出上一个操作
    friend int caculatePrePeopleSales(); //（1）	计算某个月每个人每种产品的销售量
    friend int sortSales(); //（2）	按销售量对销售员进行排序，输出排序结果；
    friend int sortAll(); //（3）	统计每种产品的总销售量，对这些产品按从高到低的顺序，输出排序结果（需输出产品的代号和销售量）；
    friend int outLable(); //（4）	输出统计报表
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


int caculatePrePeopleSales() {
    std::cout << "Function: " << "caculatePrePeopleSales" << std::endl;
    return 0;
}

int sortSales() {
    std::cout << "Function: " << "sortSales" << std::endl;
    return 0;
}

int sortAll() {
    std::cout << "Function: " << "sortAll" << std::endl;
    return 0;
}

int outLable() {
    std::cout << "Function: " << "outLable" << std::endl;
    return 0;
}



#endif // !SALES_CPP