#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size(), 1);

        int left_product = 1;
        int right_product = 1;
        int length = nums.size();
        for(int i=0; i<nums.size(); i++) {
            ans[i] *= left_product;
            ans[length-i-1] *= right_product;
            left_product *= nums[i];
            right_product *= nums[length-i-1];
        }
        return ans;
    }
};