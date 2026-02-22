#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> mem(26, 0);
        for(const auto& c : magazine) {
            mem[c-'a']++;
        }
        for(const auto& c: ransomNote) {
            if(mem[c-'a']==0) return false;
            else mem[c-'a']--;
        }
        return true;
    }
};