#include <string>

class Solution {
public:
    bool isSubsequence(std::string s, std::string t) {
        int sIndex = 0;
        for(const char& c : t) {
            if(s[sIndex] == c) {
                sIndex++;
                if(sIndex==s.length()) return true;
            }
        }
        return sIndex==s.length();
    }
};