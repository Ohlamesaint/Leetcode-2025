#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()) return false;
        vector<int> mem(26, 0);
        for(int i=0; i<s.length(); i++) {
            mem[s[i]-'a']++;
            mem[t[i]-'a']--;
        }
        for(const auto& num: mem) {
            if(num!=0) return false;
        }
        return true;
    }
};