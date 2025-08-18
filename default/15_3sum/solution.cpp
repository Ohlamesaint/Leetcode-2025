#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](const int n1, const int n2){return n1<n2;});
        vector<vector<int>> res({});
        for(int i=0; i<nums.size(); i++) {
            if(nums[i]>0) break;
            if(i>0 && nums[i]==nums[i-1]) continue;
            int left = i+1, right = nums.size()-1;
            while(left<right) {
                int sum = nums[i]+nums[left]+nums[right];
                if(sum == 0) {
                    res.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    while(left<right && nums[left] == nums[left-1]) left++;
                } else if (sum<0) {
                    left++;
                    while(left<right && nums[left] == nums[left-1]) left++;
                } else {
                    right--;
                    while(left<right && nums[right] == nums[right+1]) right--;
                }
            }
        }
        return res;

    }
};