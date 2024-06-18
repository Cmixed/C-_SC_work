#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

int EightQueen(int n) {           //函数返回八皇后问题的解法个数
	int *p = new int[n];          //p[8]用来存储八皇后的位置，下标表示行号，数值表示列号
								  //例如p[2]=3表示落在(2,3)这个点上，行号列号均为0~8
	memset(p, 0, n * sizeof(int));//初始化所有p[i]=0
	int k = 0;                    //k用来记录行号
	int count = 0;                //count用来记录解法个数，函数最终返回该值
	while (k >= 0) {              //最后一次回溯k=-1跳出循环，从而找到全部解法
		while (p[k] < n) {
			int i;
			for (i = 0; i < k; i++)//找一下K行之前的几行有没有与p[k]在同一列或者同一对角线上
				if (p[i] == p[k] || p[i] - p[k] == i - k || p[i] - p[k] == k - i)
					break;         //如果有，就跳出循环，此时i<k，否则i=k
			if (i < k)p[k]++;      //p[k]不满足条件，p[k]++，再次进入循环与前几行对比，直至p[k]满足条件，此时p[0]到p[k]之间都满足条件了
			else break;            //p[k]满足条件，跳出 while(p[k]<n) 循环
		}
		if (p[k] < n) {            //如果p[k]<n,即合法的话，进入下面代码
			if (k < n - 1)k++;     //如果还没到最后一行的话，就k++,进入下一行；如果k=7到了最后一行的话，就表明找到一组解，进入else开始输出
			else {                 //以下为打印函数，可以不看
				for (int i = 0; i < n; i++) {//i为行号
					for (int j = 0; j < p[i]; j++)cout << "|--";        //输出此行皇后之前的格子
					cout << "O";   //输出皇后O
					for (int j = 0; j < n - p[i] - 1; j++)cout << "--|";//输出此行皇后之后的格子
					cout << endl;
				}
				cout << "……………………………" << endl;
				for (int i = 0; i < n; i++)cout << p[i] + 1; cout << endl;//输出此组解法
				cout << "……………………………" << endl;
				count++;           //解法数加一
				p[k]++;            //把p[7]++  重新开始找下一个解法
			}
		}
		else {                     //p[k]=8,此行找不到解，需要回溯，更改上一行的解法
			p[k] = 0;              //重新初始化k行
			k--;                   //回到上一行
			if (k >= 0)p[k]++;     //如果还没到最后的解法，即如果不是0行找不到解的话，就可以开始回溯，将上一行的位置++
		}
	}
	
	return count;                  //函数返回count解法数量
}
 
int main() {
	int n;
	cout << "please input a number: ";
	cin >> n;                      //皇后数量
	cout << "There are " << EightQueen(n) << " methods." << endl;
	return 0;
}