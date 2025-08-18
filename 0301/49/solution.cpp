/*
Constraints:

1 <= strs.length <= 10^4
0 <= strs[i].length <= 100
strs[i] consists of lowercase English letters.
*/

#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<int>> freqEncode;
        for(int i=0; i<strs.size(); i++) {
            string newEncode(26, 0);
            for(const auto& c : strs[i]) {
                newEncode[c-'a']++;
            }
            freqEncode[newEncode].push_back(i);
        }
        vector<vector<string>> res;
        for(const auto entry: freqEncode) {
            vector<string> subRes;
            for(const auto value: entry.second) {
                subRes.push_back(strs[value]);
            }
            res.push_back(subRes);
        }
        return res;
    }
};