#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> numToLastIndex;
        for(int i=0; i<nums.size(); i++) {
            int num = nums[i];
            if(numToLastIndex.find(num) != numToLastIndex.end() && i-numToLastIndex[num] <= k) {
                return true;
            }
            numToLastIndex[num] = i;
        }
        return false;
    }
};