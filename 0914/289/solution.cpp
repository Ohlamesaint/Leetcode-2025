#include <vector>

using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> kernel({{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}});

        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++) {
                int neighbors = 0;
                for(const auto& pos: kernel) {
                    int row = i+pos[0];
                    int col = j+pos[1];
                    if(row<0 || col<0 || row>=board.size() || col>=board[0].size()) {
                        continue;
                    }
                    if(board[row][col]>0) {
                        neighbors++;
                    }
                }
                board[i][j] = board[i][j]==0?-neighbors-1:neighbors+1;
            }
        }

        for(int i=0; i<board.size(); i++) {
            for(int j=0; j<board[0].size(); j++) {
                if(board[i][j]>0) {
                    int neighbors = board[i][j]-1;
                    if(neighbors<2||neighbors>3) {
                        board[i][j] = 0;
                    } else board[i][j] = 1;
                } else {
                    int neighbors = -board[i][j]-1;
                    if(neighbors == 3) {
                        board[i][j] = 1;
                    } else {
                        board[i][j] = 0;
                    }
                }
                
            }
        }
    }
};