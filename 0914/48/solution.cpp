/**
 * @file solution.cpp
 * @author Sam Chen
 * @brief 
 * @version 0.1
 * @date 2025-09-14
 * 
 * @copyright Sam Chen (c) 2025
 * 
 * Time Complexity: O(n^2) where n is the number of rows or columns in the input matrix
 * Space Complexity: O(1) // in-place
 * 
 */

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for(int i=0; i<n; i++) {
            int left = 0, right = n-1;
            while(left<right) {
                swap(matrix[i][left], matrix[i][right]);
                left++;
                right--;
            }
        }
    }
};