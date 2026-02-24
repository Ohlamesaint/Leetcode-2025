#include <vector>

using namespace std;

class Solution {
public:
    int majorityElementOptimized(vector<int>& nums) {
        int count = 0;
        int candidate;
        for(const auto& num: nums) {
            if(count == 0) {
                candidate = num;
            }
            count += (candidate == num) ? 1 : -1;
        }
        return candidate;
    }

    int majorityElementAISolution(vector<int>& nums) {
        int count = 0;
        int majority = nums[0];
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] == majority) {
                count++;
            } else {
                if(count == 0) {
                    majority = nums[i];
                    count = 1;
                } else {
                    count--;
                }
            }
        }
        return majority;
    }


    int majorityElement(vector<int>& nums) {
        int degree = 0;
        int majority = nums[0];
        for(int i=1; i<nums.size(); i++) {
            if(nums[i]!=majority) {
                if(degree == 0) {
                    majority = nums[i];
                } else {
                    degree--;
                }
            } else {
                degree++;
            }
        }
        return majority;
    }
};