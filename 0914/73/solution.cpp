/**
 * @file solution.cpp
 * @author Sam Chen
 * @brief 
 * @version 0.1
 * @date 2025-09-14
 * 
 * @copyright Sam Chen (c) 2025
 * 
 * Time Complexity: O(m * n) where m is the number of rows and n is the number of columns in the input matrix
 * Space Complexity: O(1) // in-place
 */

#include <vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool isFirstColumnZero = false;
        bool isFirstRowZero = false;
        
        int row = matrix.size();
        int col = matrix[0].size();
        for(int i=0; i<row; i++) {
            if(matrix[i][0] == 0) {
                isFirstColumnZero = true;
            }
        }
        for(int i=0; i<col; i++) {
            if(matrix[0][i] == 0) {
                isFirstRowZero = true;
            }
        }

        for(int i=1; i<row; i++) {
            for(int j=1; j<col; j++) {
                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for(int i=1; i<row; i++) {
            if(matrix[i][0]==0) {
                for(int j=0; j<col; j++) {
                    matrix[i][j] = 0;
                }
            }
        }
        for(int i=1; i<col; i++) {
            if(matrix[0][i]==0) {
                for(int j=0; j<row; j++) {
                    matrix[j][i] = 0;
                }
            }
        }

        if(isFirstColumnZero) {
            for(int i=0; i<row; i++) {
                matrix[i][0] = 0;
            }
        }

        if(isFirstRowZero) {
            for(int i=0; i<col; i++) {
                matrix[0][i] = 0;
            }
        }
    }
};