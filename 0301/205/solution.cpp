#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int len = s.length();
        if(t.length()!=len) return false;
        unordered_map<char, char> s2t;
        unordered_map<char, char> t2s;
        for(int i=0; i<len; i++) {
            if(s2t.find(s[i])!=s2t.end() && s2t[s[i]]!=t[i]) {
                return false;
            } else if(t2s.find(t[i])!=t2s.end() && t2s[t[i]]!=s[i]) {
                return false;
            } else {
                s2t[s[i]] = t[i];
                t2s[t[i]] = s[i];
            }
        }
        return true;
    }
};