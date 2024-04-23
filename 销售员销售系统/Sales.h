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
    friend int Function1();
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


// int Function1() {
//     cout << "Function1" << endl;
//     return 0;
// }





#endif // !SALES_H