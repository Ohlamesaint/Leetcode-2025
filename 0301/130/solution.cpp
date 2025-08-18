#include <vector>

using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        for(int i=0; i<board.size(); i++) {
           if(board[i][0]=='O') dfs(board, i, 0);
           if(board[i][board[0].size()-1]=='O') dfs(board, i, board[0].size()-1);
        }
        for(int j=0; j<board[0].size(); j++) {
            if(board[0][j]=='O') dfs(board, 0, j);
            if(board[board.size()-1][j]=='O') dfs(board, board.size()-1, j);
        }
        for(int i=0; i<board.size(); i++) {
            for(int j=0; j<board[0].size(); j++) {
                if(board[i][j] == 'O') board[i][j] = 'X';
                if(board[i][j] == '$') board[i][j] = 'O';
            }
        }
        
    }
private:
    void dfs(vector<vector<char>>& board, int row, int col) {
        if(row<0 || row==board.size() || col<0 || col==board.back().size() || board[row][col]=='X' || board[row][col] == '$') return;
        board[row][col] = '$';
        dfs(board, row-1, col);
        dfs(board, row+1, col);
        dfs(board, row, col-1);
        dfs(board, row, col+1);
    }
};