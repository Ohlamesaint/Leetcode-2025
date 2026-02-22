/**
 * @file solution.cpp
 * @author Sam Chen
 * @brief 
 * @version 0.1
 * @date 2025-09-08
 * 
 * @copyright Sam Chen (c) 2025
 * 
 * Time Complexity: O(m*n) where m is the number of rows and n is the number of columns in the input matrix
 * Space Complexity: O(1) since we are using the output array to store the result
 */

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        res.reserve(matrix.size()*matrix[0].size());

        vector<pair<int, int>> directions({{0, 1}, {1, 0}, {0, -1}, {-1, 0}});
        int directionIndex = 0;
        int row = 0, col = 0, steps = 0, depth = 0;
        while(steps<matrix.size()*matrix[0].size()) {
            res.emplace_back(matrix[row][col]);
            matrix[row][col] = -101;
            int nextRow = row+directions[directionIndex].first;
            int nextCol = col+directions[directionIndex].second;
            if(nextRow<0 || nextRow>=matrix.size() ||
            nextCol<0 || nextCol>=matrix[0].size() || matrix[nextRow][nextCol] == -101) {
                directionIndex = (directionIndex+1) %4;
            }

            row = row+directions[directionIndex].first;
            col = col+directions[directionIndex].second;
            steps++;
        }
        return res;
    }
};