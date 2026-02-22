/**
 * @file solution.cpp
 * @author Sam Chen
 * @brief 
 * @version 0.1
 * @date 2025-09-08
 * 
 * @copyright Sam Chen (c) 2025
 * 
 * Time Complexity: O(1) // since the board size is fixed
 * Space Complexity: O(1)
 * 
 */

#include <vector>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        for(int i=0; i<9; i++) {
            vector<bool> rowMem(9, false);
            vector<bool> colMem(9, false);
            for(int j=0; j<9; j++) {
                if(board[i][j] != '.') {
                    if(rowMem[board[i][j]-1]) return false;
                    else rowMem[board[i][j]-1] = true;
                }
                
                if(board[j][i] != '.') {
                    if(colMem[board[j][i]-1]) return false;
                    else colMem[board[j][i]-1] = true;
                }
            }
        }

        vector<pair<int, int>> offsets({{0, 0}, {0, 1}, {0, 2}, {1, 0}, {1, 1}, {1, 2}, {2, 0}, {2, 1}, {2, 2}});
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                int startRow = i*3;
                int startCol = j*3;
                vector<bool> mem(9, false);
                for(auto& offset: offsets) {
                    int row = startRow+offset.first;
                    int col = startCol+offset.second;
                    if(board[row][col] != '.') {
                        if(mem[board[row][col]-1]) return false;
                        mem[board[row][col]-1] = true;
                    }
                    
                }
            }
        }
        return true;
    }
};