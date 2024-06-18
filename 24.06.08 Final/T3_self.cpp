/*
这段代码实现了使用回溯算法的递归方式解决八皇后问题，并且仅输出一种解决方案。
代码中的 is_valid 函数检查在当前行和列上放置一个皇后是否安全，
queens_placement 函数递归地尝试在棋盘上放置皇后，一旦八个皇后都放置好，
就打印棋盘并增加解决方案的计数。最后，在main函数中，我们初始化棋盘，
调用 queens_placement 函数，并在结束时打印出总的解决方案数。	
*/


#include <iostream>
#include <cstring>
 
int n = 0; 
int count = 0;
int board[100][100];
 
void print_board() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
 
bool is_valid(int row, int col) {
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1) return false;
    }
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) return false;
    }
    for (int i = row - 1, j = col + 1; i >= 0 && j < 8; i--, j++) {
        if (board[i][j] == 1) return false;
    }
    return true;
}
 
bool queens_placement(int row) {
    if (row >= n) {
        print_board();
        count++;
        return true;
    }
    for (int col = 0; col < n; col++) {
        if (is_valid(row, col)) {
            board[row][col] = 1;
            if (queens_placement(row + 1)) return true; // backtracking
            board[row][col] = 0;
        }
    }
    return false;
}
 
int main() {
	std::cin >> n;
    memset(board, 0, sizeof(board));
    queens_placement(0);
    // std::cout << "Total solutions: " << count << std::endl;
    return 0;
}