#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> num2index;

        for(int i=0; i<nums.size(); i++) {
            if(num2index.find(nums[i])!=num2index.end()) return {i, num2index[nums[i]]};
            num2index[target-nums[i]] = i;
        }

        return {};
    }
};