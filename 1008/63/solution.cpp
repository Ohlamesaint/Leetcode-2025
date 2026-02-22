#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row = obstacleGrid.size(), col = obstacleGrid[0].size();
        if(obstacleGrid[0][0] == 1) return 0;
        obstacleGrid[0][0] = 1;

        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                if(i==0 && j==0) {
                    continue;
                }
                if(obstacleGrid[i][j] == 1) {
                    obstacleGrid[i][j] = 0;
                    continue;
                } 
                int ways = 0;
                if(i-1>=0) {
                    ways+=obstacleGrid[i-1][j];
                }
                if(j-1>=0) {
                    ways+=obstacleGrid[i][j-1];
                }
                obstacleGrid[i][j] = ways;
            }
        }
        return obstacleGrid.back().back();

    }
};

// https://youtu.be/QXM32B329g8?si=En95-_4mTNwjGB85