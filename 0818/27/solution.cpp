#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int index = nums.size();
        int i = 0;
        while(i<index){
            if(nums[i] == val) {
                swap(nums[i], nums[index-1]);
                index--;
            } else {
                i++;
            }
        }
        return index;
    }
};