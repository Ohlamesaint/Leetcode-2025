#include <vector>

using namespace std;

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int negativeIndex = n-1, sum = 0;
        for(int i=0; i<m; i++) {
            while(negativeIndex>=0 && grid[i][negativeIndex] < 0) {
                negativeIndex--;
            }
            sum += n-negativeIndex-1;
        }
        return sum;
    }
};