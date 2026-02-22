#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> needToIndex;
        needToIndex.reserve(nums.size());

        for(int i=0; i<nums.size(); i++) {
            if(needToIndex.find(nums[i]) != needToIndex.end()) {
                return {needToIndex[nums[i]], i};
            } 
            needToIndex[target-nums[i]] = i;
            
        }
        return {};
    }
};