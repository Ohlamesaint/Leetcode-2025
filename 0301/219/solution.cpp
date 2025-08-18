#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> num2freq;
        for(int i=0; i<min(static_cast<int>(nums.size()), k+1); i++) {
            if(num2freq.find(nums[i])!=num2freq.end() && num2freq[nums[i]]!=0) return true;
            num2freq[nums[i]]++;
        }
        for(int i=k+1; i<nums.size(); i++) {
            num2freq[nums[i-k-1]]--;
            if(num2freq.find(nums[i])!=num2freq.end() && num2freq[nums[i]]!=0) return true;
            num2freq[nums[i]]++;
        }
        return false;
    }
};