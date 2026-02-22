/**
 * @file solution.cpp
 * @author Sam Chen
 * @brief 
 * @version 0.1
 * @date 2025-09-07
 * 
 * @copyright Copyright (c) 2025
 * 
 * Time Complexity: O(m+n) where m is the length of haystack and n is the length of needle
 * Space Complexity: O(n) for the lps array
 * 
 */

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = needle.length();
        int m = haystack.length();  
        vector<int> lps(n, 0);
        int len = 0;
        for(int i=1; i<n; i++) {
            while(len>0 && needle[i]!=needle[len]) {
                len = lps[len-1];
            }
            if(needle[len]==needle[i]) {
                len++;
            }
            lps[i] = len;
        }


        len = 0;
        for(int i=0; i<m; i++) {
            while(len>0 && haystack[i]!=needle[len]) {
                len = lps[len-1];
            }
            if(haystack[i] == needle[len]) {
                len++;
            }
            if(len == n) return i-n+1;
        }
        return -1;
    }
};