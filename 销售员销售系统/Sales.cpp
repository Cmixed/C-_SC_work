#ifndef SALES_CPP
#define SALES_CPP

#include <iostream>
#include <iomanip>

using namespace std;

const int SALES_NUMBER = 5;
class Sales
{
private:
    /* data */
    char order_ = 'N';
    int arr[5] = { 0 }; 
    long long int sum_ = 0;
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
    void sum();

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

void Sales::sum()
{
    for (auto val : arr)
    {
        sum_ += val; 
    }
}

void Sales::display()
{
    cout << "售货员 " << order_ << " 的各物品售货量" << endl;
    cout << "货物 1 的销售量为: " << arr[0] << endl; 
    cout << "货物 2 的销售量为: " << arr[1] << endl; 
    cout << "货物 3 的销售量为: " << arr[2] << endl; 
    cout << "货物 4 的销售量为: " << arr[3] << endl; 
    cout << "货物 5 的销售量为: " << arr[4] << endl; 
}

// 1)计算某个月每个人每种产品的销售量
int caculatePrePeopleSales(Sales sales[]) 
{
    std::cout << endl;
    std::cout << "本月每个人每种产品的销售量：\n\n";
    for (int i = 0; i < SALES_NUMBER; i++)
    {
        sales[i].display();
        std::cout << std::endl;
    }
    return 0;
}
//（2）	按销售量对销售员进行排序，输出排序结果；
int sortSales(Sales sales[]) 
{

    long long arr[SALES_NUMBER][5];

    for (int i = 0; i < SALES_NUMBER; i++)
    {
        arr[i][0] = i;
        arr[i][1] = sales[i].sum_;
    }
    
    for (int i = 0; i < SALES_NUMBER-1; i++)
    {
        for (int j = 0; j < SALES_NUMBER-i-1; j++)
        {
            long long temp1 = 0, temp0 = 0;
            if (arr[j][1] < arr[j+1][1])
            {
                temp1 = arr[j][1];  temp0 = arr[j][0];
                arr[j][1] = arr[j+1][1];
                arr[j][0] = arr[j+1][0];
                arr[j+1][1] = temp1;
                arr[j+1][0] = temp0;
            }
        }
    }

    std::cout << std::endl;
    std::cout << "按销售量对销售员进行排序的排序结果；\n";
    std::cout << std::endl;
    std::cout << "排   名             数  量\n";
    
    for (int i = 0; i < SALES_NUMBER; i++)
    {
        std::cout << "第 ";
        std::cout.width(3);
        std::cout << i+1;
        std::cout << " : 销售员 " << (char)('A'+arr[i][0]) << " " ;
        std::cout.width(5);
        std::cout << arr[i][1]; 
        std::cout << endl;
    }

    return 0;
}
//（3）	统计每种产品的总销售量，对这些产品按从高到低的顺序，输出排序结果（需输出产品的代号和销售量）；
int sortAll(Sales sales[])
{
    std::cout << std::endl;
    std::cout << "统计每种产品的总销售量（高到低）:" << std::endl;
    long long sto[SALES_NUMBER][2] = { 0 };
    // 初始化 sto[][0] 为 物品序号
    for (int i = 0; i < SALES_NUMBER; i++)
    {
        sto[i][0] = i;
    }
    // 计算每种物品的总销售量 存入 sto[][1]
    for (int i = 0; i < SALES_NUMBER; i++)
    {
        for (int j = 0; j < SALES_NUMBER; j++)
        {
            sto[i][1] += sales[j].arr[i];
        }
    }
    // 进行冒泡排序
    for (int i = 0; i < SALES_NUMBER-1; i++)
    {
        for (int j = 0; j < SALES_NUMBER-i-1; j++)
        {
            long long temp1 = 0, temp0 = 0;
            if (sto[j][1] < sto[j+1][1])
            {
                temp1 = sto[j][1]; temp0 = sto[j][0];
                sto[j][1] = sto[j+1][1];
                sto[j][0] = sto[j+1][0];
                sto[j+1][1] = temp1;
                sto[j+1][0] = temp0;
            }
        }
    }
    
    std::cout << std::endl;
    std::cout << "每种产品的总销售量（高到低）：\n";
    std::cout << std::endl;
    std::cout << "排   名           数  量\n"; 

    for (int i = 0; i < SALES_NUMBER; i++)
    {
        std::cout << "第 ";
        std::cout.width(3);
        std::cout << i+1;
        std::cout << " : 货物 " << sto[i][0]+1 << " " ;
        std::cout.width(5);
        std::cout << sto[i][1]; 
        std::cout << endl;
    }
    
    return 0;
}
//（4）	输出统计报表
int outLable(Sales sales[])
{
    using namespace std;

    std::cout << "统计报表：\n\n";

    // 来自 sortSales() 计算出每个销售员的销售量
    //（2）	按销售量对销售员进行排序，输出排序结果；
    long long arr[SALES_NUMBER][5];

    for (int i = 0; i < SALES_NUMBER; i++)
    {
        arr[i][0] = i;
        arr[i][1] = sales[i].sum_;
    }
    
    // 来自 sortAll() 计算出每种产品的总销售量
    //（3）	统计每种产品的总销售量，对这些产品按从高到低的顺序，输出排序结果（需输出产品的代号和销售量）；
    long long sto[SALES_NUMBER][2] = { 0 };
    // 初始化 sto[][0] 为 物品序号
    for (int i = 0; i < SALES_NUMBER; i++)
    {
        sto[i][0] = i;
    }
    // 计算每种物品的总销售量 存入 sto[][1]
    for (int i = 0; i < SALES_NUMBER; i++)
    {
        for (int j = 0; j < SALES_NUMBER; j++)
        {
            sto[i][1] += sales[j].arr[i];
        }
    }

    // long long arr[SALES_NUMBER][5] 存储售货员的销售数据
    // long long sto[SALES_NUMBER][2] 存储货物的数据


    ios_base::fmtflags old = cout.setf(ios::left, ios::adjustfield);

    // 20 25 10
    // START Line
    cout << setw(20) << "销售员代号" << setw(25) << "             产品代码           " << setw(10) << "   每人销售产品总量" << endl;
    // L0
    cout << setw(20) << " " << setw(6) << "1" << setw(6) << "2" << setw(6) << "3" << setw(6) << "4" << setw(6) << "5" << setw(10) << " " << endl;
    // L1
    cout << setw(20) << "    A" << setw(6) << sales[0].arr[0] << setw(6) << sales[0].arr[1] << setw(6) << sales[0].arr[2] << setw(6) << sales[0].arr[3] << setw(6) << sales[0].arr[4] << setw(10) << arr[0][1] << endl;
    // L2
    cout << setw(20) << "    B" << setw(6) << sales[1].arr[0] << setw(6) << sales[1].arr[1] << setw(6) << sales[1].arr[2] << setw(6) << sales[1].arr[3] << setw(6) << sales[1].arr[4] << setw(10) << arr[1][1] << endl;
    // L3
    cout << setw(20) << "    C" << setw(6) << sales[2].arr[0] << setw(6) << sales[2].arr[1] << setw(6) << sales[2].arr[2] << setw(6) << sales[2].arr[3] << setw(6) << sales[2].arr[4] << setw(10) << arr[2][1] << endl;
    // L4
    cout << setw(20) << "    D" << setw(6) << sales[3].arr[0] << setw(6) << sales[3].arr[1] << setw(6) << sales[3].arr[2] << setw(6) << sales[3].arr[3] << setw(6) << sales[3].arr[4] << setw(10) << arr[3][1] << endl;
    // L5
    cout << setw(20) << "    E" << setw(6) << sales[4].arr[0] << setw(6) << sales[4].arr[1] << setw(6) << sales[4].arr[2] << setw(6) << sales[4].arr[3] << setw(6) << sales[4].arr[4] << setw(10) << arr[4][1] << endl;
    // END Line
    cout << setw(20) << "每种产品销售总量    " << setw(6) << sto[0][1] << setw(6) << sto[1][1] << setw(6) << sto[2][1] << setw(6) << sto[3][1] << setw(6) << sto[4][1] << setw(10) << " " << endl;

    cout.setf(old, ios::adjustfield);

    return 0;
}

// 5)输出上一个操作
int funcLastOption(int lastOption) {

    std::cout << endl;
    std::cout << "上一个操作是： "<< lastOption << std::endl;
    std::cout << "如果想要知道更多历史操作，请查看目录下文件 option.txt" << std::endl;
    std::cout << endl;
    return lastOption;
}

void Sales::caculateSales(int as, int bs, int cs, int ds, int es)
{
    arr[0] += as;   arr[1] += bs;
    arr[2] += cs;   arr[3] += ds;
    arr[4] += es;
}

#endif // !SALES_CPP