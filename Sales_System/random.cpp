// 销售员销售系统 配套 销售数据生成工具
// 随机生成销售员的销售数据

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

/*
* 主函数：生成指定月份和次数的销售数据，并写入到文件中。
* 参数：
* - argc: int类型，命令行参数数量。
* - argv: const char*类型数组，命令行参数值。
* 返回值：
* - 无。
*/
int main(int argc, char const *argv[])
{
    int month = 0; int times = 0; // 初始化月份和需要生成的记录条数

    // 输出欢迎信息，并提示输入月份和记录条数
    cout << "销售员销售系统 配套 销售数据生成工具：\n\n";
    cout << "输入月份 与 需要的记录条数:\n\n";

    // 从用户输入中读取月份和记录条数
    cin >> month >> times;

    // 创建并打开文件，准备写入数据
    ofstream fout("random.txt", ios_base::out | ios_base::trunc);
	
    // 循环生成指定次数的销售记录，并写入文件
    for (int i = 0; i < times; i++)
    {
        // 随机生成销售员代号
        char sales = 'A';
        sales += rand()%5;

        // 构造销售记录并写入文件
        fout << month << sales 
            << " 1 "<< rand()%10+1 << " 2 " << rand()%10+1
            << " 3 " << rand()%10+1 << " 4 " << rand()%10+1
            << " 5 " << rand()%10+1 << '\n';
    }
	
    // 关闭文件
    fout.close();
	
    // 输出成功信息
    cout << endl;
    cout << "生成成功，请查看目录下 random.txt";

    return 0;
}