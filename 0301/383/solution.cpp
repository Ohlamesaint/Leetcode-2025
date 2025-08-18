#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> freq;
        for(const auto & c: magazine) {
            freq[c]++;
        }

        for(const auto & c: ransomNote) {
            if(freq[c] == 0) {
                return false;
            }
            freq[c]--;
        }
        return true;
    }
};