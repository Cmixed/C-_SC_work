#ifndef _SALES_CPP
#define _SALES_CPP

#include <iostream>
#include <iomanip>
#include <vector>
#include <thread>
#include <cstdlib>
#include <string>

using namespace std;

// 全局变量
const int SALES_NUMBER = 5;
const int GOODS_NUMBER = 5;
const int OPTION_NUMBER = 6;

// Sales 类
class Sales
{
private:
    /* data */
    char order_ = 'N';
    int arr[GOODS_NUMBER] = { 0 }; 
    long long int sum_ = 0;
public:
    Sales() = default;
    Sales(int SalseOrder, int as, int bs, int cs, int ds, int es)
    {
        char order = (char)(SalseOrder + 'A');
        order_ = order;
        arr[0] = as;    arr[1] = bs;
        arr[2] = cs;    arr[3] = ds;
        arr[4] = es;
    }
    ~Sales();

// 普通成员函数列表
    void order(char order);
    void display(); // 显示成员数据
    void caculateSales(int as, int bs, int cs, int ds, int es);   // 累加计算
    void sum();
// 友元函数列表
    friend int sortSales(Sales sales[]); //（2）	按销售量对销售员进行排序，输出排序结果；
    friend int sortGoods(Sales sales[]); //（3）	统计每种产品的总销售量，对这些产品按从高到低的顺序，输出排序结果（需输出产品的代号和销售量）；
    friend int outLable(Sales sales[]); //（4）	输出统计报表
};

// 函数列表
// 选项操作
int caculatePrePeopleSales(Sales sales[]); //（1）	计算某个月每个人每种产品的销售量
int sortSales(Sales sales[]); //（2）	按销售量对销售员进行排序，输出排序结果；
int sortGoods(Sales sales[]); //（3）	统计每种产品的总销售量，对这些产品按从高到低的顺序，输出排序结果（需输出产品的代号和销售量）；
int outLable(Sales sales[]); //（4）	输出统计报表
int funcHistoryOption(int lastOption); //（5） 获取更多历史操作
void sortPure(Sales sales[], long long (*arr)[2] );  // 二维数组排序 arr[SALES_NUMBER][2] 类型 (2 (3 (4 使用

void initSales(Sales sales[]);   // 清零
void switchOptionText(int option);


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

// 显示成员数据
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

    long long arr[SALES_NUMBER][2] = { 0 };

    for (int i = 0; i < SALES_NUMBER; i++)
    {
        arr[i][0] = i;
        arr[i][1] = sales[i].sum_;
    }
    
    sortPure(sales, arr);  // 排序

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
int sortGoods(Sales sales[])
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

    sortPure(sales, sto);  // 排序
    
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

    std::cout << endl;
    std::cout << "统计报表：\n\n";

    // 来自 sortSales() 计算出每个销售员的销售量
    //（2）	按销售量对销售员进行排序，输出排序结果；
    long long arr[SALES_NUMBER][2] = { 0 };

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


    // 设置格式 左对齐，将旧格式存储起来
    ios_base::fmtflags old = cout.setf(ios::left, ios::adjustfield);

    // 文件格式 ： 20 25 10

    // START Line
    cout << setw(20) << "销售员代号" << setw(25) << "            产品代码          " << setw(10) << "每人销售产品总量" << endl;
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

    // 智能建议所需要的数据处理
    // 多线程操作,创建并启动两个线程来对不同的数据集进行排序

    std::thread t1 ([&sales, &arr]() {  // 使用 lamda 表达式传递给启动线程的函数的参数
        sortPure(sales, arr);
    });
    std::thread t2 ([&sales, &sto]() {  // lamda 表达式
        sortPure(sales, sto);      // [捕获列表](参数列表)->返回类型{函数体}
    });

    vector<std::thread> threads;    // 创建 vector 泛型模板的 thread 显式实例化对象 以管理线程

    threads.push_back(std::move(t1));   // 将线程加入 threads 对象，使用 move 以移交线程所有权
    threads.push_back(std::move(t2));   

    // 等待线程完成操作
    for (auto & val : threads)
    {
        val.join(); // 合并线程
    }

    // 智能建议
    cout << "\n";
    cout << "一下是根据统计报表的数据所给出的建议:\n\n";

    cout << "销售员中业绩最高的为 销售员 " << (char)(arr[0][0]+'A') << " 共卖出 " << setw(5) << arr[0][1] << "件" << endl;
    cout << "销售员中业绩最低的为 销售员 " << (char)(arr[4][0]+'A') << " 共卖出 " << setw(5) << arr[4][1] << "件" << endl;
    cout << "\n可以给予销售员 " << (char)(arr[0][0]+'A') << " 表彰," << "提醒销售员 " << (char)(arr[4][0]+'A') << " 向其学习。\n";
    cout << endl;
    cout << "销售量最高的为 货物 " << sto[0][0]+1 << " 共卖出 " << setw(5) << sto[0][1] << "件" << endl;
    cout << "销售量最低的为 货物 " << sto[4][0]+1 << " 共卖出 " << setw(5) << sto[4][1] << "件" << endl;
    cout << "\n可以加大货物 " << sto[0][0]+1 << " 的进货量," << "减少货物 " << sto[4][0]+1 << " 的进货量。\n";

    // 恢复文件格式
    cout.setf(old, ios::adjustfield);

    return 0;
}

// 5)输出上一个操作
/**
 * @brief 显示历史操作选项的函数
 * 
 * 该函数尝试在当前目录下打开一个名为option.txt的文件，以便用户查看更多的历史操作信息。
 * 如果文件打开失败，将向用户显示错误信息。
 * 
 * @param lastOption 上一次选择的选项，函数将其原样返回。
 * @return int 返回上一次选择的选项。
 */
int funcHistoryOption(int lastOption) {

    // 向用户提示可以打开option.txt文件查看历史操作
    std::cout << endl << "打开目录下文件 option.txt ，获取更多历史操作。" << std::endl;
    std::cout << endl;

    // 定义要打开的文件名
    std::string filename = ".\\option.txt"; 

    // 尝试使用系统命令打开文件，如果失败则输出错误信息
    if (system(("start " + filename).c_str() ) ) {
        std::cerr << "文件打开失败: " << filename << "!" << std::endl;
        std::cerr << "请检查系统完备性。" << std::endl;
    }
 
    // 文件打开成功，向用户提示
    std::cout << "文件已成功打开: " << filename <<  "!" << std::endl;

    // 返回上一次选择的选项
    return lastOption;
}

void Sales::caculateSales(int as, int bs, int cs, int ds, int es)
{
    arr[0] += as;   arr[1] += bs;
    arr[2] += cs;   arr[3] += ds;
    arr[4] += es;
}

void sortPure(Sales sales[], long long (*arr)[2] )  // 二维数组排序 arr[SALES_NUMBER][2] 类型
{
    // 冒泡排序, 由大到小
    for (int i = 0; i < SALES_NUMBER-1; i++)
    {
        for (int j = 0; j < SALES_NUMBER-i-1; j++)
        {
            long long temp0 = 0, temp1 = 0;
		    if (arr[j][1] < arr[j+1][1])
		    {
			    temp0 = arr[j][0]; temp1 = arr[j][1];
			    arr[j][0] = arr[j+1][0];
			    arr[j][1] = arr[j+1][1];
			    arr[j+1][0] = temp0;
			    arr[j+1][1] = temp1;
		    }
        }
    }

}    


void switchOptionText(int option)
{
    switch (option) // 添加操作代号注释
    {
        case 0:
            cout << " ：退出系统\n";
            break;
        case 1:
            cout << " ：计算某个月每个人每种产品的销售量\n";
            break;
        case 2:
            cout << " ：按销售量对销售员进行排序\n";
            break;
        case 3:
            cout << " ：统计每种产品的总销售量（高到低）\n";
            break;
        case 4:
            cout << " ：输出统计报表\n";
            break;
        case 5:
            cout << " ：获取更多历史操作\n";
            break;
        case 6:
            cout << " ：更改操作月份\n";
            break;
        default:
            break;
    }
}

// 清零
void initSales(Sales sales[])
{
    for (int i = 0; i < SALES_NUMBER; i++)
    {
        sales[i] = Sales(i, 0, 0, 0, 0, 0);
    }
}


#endif // !_SALES_CPP