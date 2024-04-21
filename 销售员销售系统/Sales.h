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
};

Sales::Sales(int goodOrder, int goodMumber)
{
    // 序号比数组的序号大一，所以 arr[]参数要减一
    arr[--goodOrder] = goodMumber;
}

Sales::~Sales()
{
    
}








#endif // !SALES_H