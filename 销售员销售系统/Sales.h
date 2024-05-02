#ifndef SALES_H
#define SALES_H



class Sales
{
private:
    /* data */
    int arr[5] = { 0 }; 
public:
    Sales() = default;
    Sales(int goodOrder, int goodMumber);
    ~Sales();
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



#endif // !SALES_H