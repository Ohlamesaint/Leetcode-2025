#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.size());
        for(const auto& num: nums) {
            numSet.insert(num);
        }
        int maxConsecutive = 0;
        for(const auto& num: numSet) {
            if(numSet.find(num-1) != numSet.end()){
                continue;
            } else {
                int numTemp = num;
                while(numSet.find(numTemp) != numSet.end()) {
                    numTemp++;
                }
                maxConsecutive = max(maxConsecutive, numTemp-num);
            }
        }
        return maxConsecutive;

    }
};