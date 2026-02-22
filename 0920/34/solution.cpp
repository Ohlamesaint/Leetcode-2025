#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int lower = lowerBound(nums, target);
        int upper = upperBound(nums, target);
        if(lower == upper) return {-1, -1};

        return {lower, upper-1};
    }

private:
    int lowerBound(vector<int>& nums, int target) {
        int left = 0, right = nums.size();
        while(left<right) {
            int mid = left + (right-left)/2;
            if(nums[mid]<target) {
                left = mid+1;
            } else {
                right = mid;
            }
        }
        return  left;
    }   

    int upperBound(vector<int>& nums, int target) {
        int left = 0, right = nums.size();
        while(left<right) {
            int mid = left + (right-left)/2;
            if(nums[mid]<=target){
                left = mid+1;
            } else {
                right = mid;
            }
        }
        return  left;
    }
};