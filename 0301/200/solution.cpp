#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                if(grid[i][j]=='1') {
                    count++;
                    auto q = queue<pair<int, int>>();
                    q.push(make_pair(i, j));
                    while(!q.empty()) {
                        auto position = q.front();
                        q.pop();
                        int row = position.first, col = position.second;
                        if(row<0 || row==grid.size() || col<0 || col == grid[0].size() || grid[row][col] == '0') continue;
                        grid[row][col] = '0';
                        q.push(make_pair(row-1, col));
                        q.push(make_pair(row+1, col));
                        q.push(make_pair(row, col-1));
                        q.push(make_pair(row, col+1));
                    }
                }
            }
        }
        return count;
    }

};