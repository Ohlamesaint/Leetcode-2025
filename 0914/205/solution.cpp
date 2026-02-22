#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length()!=t.length()) return false;
        vector<char> mem(128, 0);
        vector<bool> isMapped(128, false);
        for(int i=0; i<s.length(); i++) {
            if(mem[s[i]]==0) {
                if(isMapped[t[i]]) return false;
                mem[s[i]] = t[i];
                isMapped[t[i]] = true;
            } else if(mem[s[i]]!=t[i]) {
                return false;
            }
        }
        return true;
    }
};