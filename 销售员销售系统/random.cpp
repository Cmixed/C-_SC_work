// 销售员销售系统 配套 销售数据生成工具
// 随机生成销售员的销售数据

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main(int argc, char const *argv[])
{
	int month = 0; int times = 0;

	cout << "销售员销售系统 配套 销售数据生成工具：\n\n";
	cout << "输入月份 与 需要的记录条数:\n\n";

	cin >> month >> times;

	ofstream fout("random.txt", ios_base::out | ios_base::trunc);
	
	for (int i = 0; i < times; i++)
	{
		char sales = 'A';
		sales += rand()%5;

		fout << month << sales 
			<< " 1 "<< rand()%10+1 << " 2 " << rand()%10+1
			<< " 3 " << rand()%10+1 << " 4 " << rand()%10+1
			<< " 5 " << rand()%10+1 << '\n';
	}
	
	fout.close();
	
	cout << endl;
	cout << "生成成功，请查看目录下 random.txt";

	return 0;
}