// Leetcode 37 : http://leetcode.com/problems/sudoku-solver/description/ 


#include<iostream>
#include<vector>
 using namespace std;

 class Solution {
public:
    bool isSafe(vector<vector<char>>& board, int r, int c, int j) {
        for (int i = 0; i < 9; i++) {
            if (board[r][i] - '0' == j)
                return false;
        }
        for (int i = 0; i < 9; i++) {
            if (board[i][c] - '0' == j)
                return false;
        }

        int x = (r / 3) * 3;
        int y = (c / 3) * 3;

        for (int i = x; i < x + 3; i++) {
            for (int k = y; k < y + 3; k++) {
                if (board[i][k] - '0' == j)
                    return false;
            }
        }

        return true;
    }

    bool f(vector<vector<char>>& board, int r, int c, int n) {

        if (r == n) {
            return true;
        }
        if (c == n) {
           
            return  f(board, r + 1, 0, n);
        }

        if (r < 0 and c < 0)
            return false;

        if (board[r][c] != '.') {
           
            return  f(board, r, c + 1, n);
        }
        for (int j = 1; j <= 9; j++) {
            if (isSafe(board, r, c, j)) {
                board[r][c] = j + '0';
                bool t = f(board, r, c + 1, n);

                if(t) return true;
                board[r][c] = '.';
            }
        }

        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        int n = board.size();
        f(board, 0, 0, n);
        return;
    }
};

 int main (){

 }