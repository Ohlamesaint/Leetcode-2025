#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int start = 0;
        unordered_map<char, string> char2String;
        unordered_map<string, char> string2char;
        int len = pattern.length();
        for(int i=0; i<len; i++) {
            if(start>s.length()) return false;
            string nextSeg = splitNextString(s, start);
            if(char2String.count(pattern[i]) && char2String[pattern[i]] != nextSeg) return false;
            if(string2char.count(nextSeg) && string2char[nextSeg] != pattern[i]) return false;
            char2String[pattern[i]] = nextSeg;
            string2char[nextSeg] = pattern[i];
            start += nextSeg.length()+1;
        }
        return start == s.length()+1;
    }

private:
    string splitNextString(string s, int start) {
        int end = start;
        while(s.length()>end && s[end]!=' ') {
            end++;
        }
        return s.substr(start, end-start);
    }
};