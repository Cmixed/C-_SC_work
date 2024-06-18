#include <stdio.h>

int count = 0;
int chess[16][16]={0};

int notDanger( int row, int col ,int n)
{
	int i,k;
	// 判断列方向
	for( i=0; i < n; i++ )
	{
		if( chess[i][col]==1 )
		{
			return 0;
		}
	}
	// 判断左对角线 
	for( i=row, k=col; i>=0 && k>=0; i--, k-- )
	{
		if(chess[i][k]==1  )
		{
			return 0;
		}
	}
	// 判断右对角线 
	for( i=row, k=col; i>=0 && k<n; i--, k++ )
	{
		if(chess[i][k]==1  )
		{
			return 0;
		}
	}
	return 1;
}

void Print(int n)          //打印结果 
{
	static int times = 0;
	if (!times)
	{
		int row,col;
		printf("第 %d 种\n", count+1);
		for( row=0; row < n; row++ )
		{
			for( col=0; col< n; col++ )
			{
				if(chess[row][col]==1)        //皇后用‘0’表示
				{
					printf("0 ");
				}
				else
				{
					printf("# ");
				}
			}
			printf("\n");
		}
		printf("\n");		
		
		times++;
	}
	
}

void EightQueen( int row ,int n)
{
	int col;
	if( row>n-1 )                       //如果遍历完八行都找到放置皇后的位置则打印
	{
		Print(n);                       //打印八皇后的解 
		count++;
		return ;
	}
	for( col=0; col < n; col++ )        //回溯，递归
	{
		if( notDanger( row, col,n ) )    // 判断是否危险
		{
			chess[row][col]=1;
			EightQueen(row+1,n);
			chess[row][col]=0;           //清零，以免回溯时出现脏数据
		}
	}

}

int main()
{
	int n;
	scanf("%d",&n);
	EightQueen(0,n);        
	printf("总共有 %d 种解决方法!\n\n", count);
	return 0;
}