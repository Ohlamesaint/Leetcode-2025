#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.size() == 0) return {};
        int startIndex = 0, tailIndex = 1;

        vector<string> res;

        while(tailIndex<nums.size()) {
            if(nums[tailIndex]-1==nums[tailIndex-1]) {
                tailIndex++;
                continue;
            }
            res.push_back(constructString(nums, startIndex, tailIndex));
        
            startIndex = tailIndex;
            tailIndex++;
        };
        res.push_back(constructString(nums, startIndex, tailIndex));

        return res;
    }

private:

    string constructString(vector<int>& nums, int startIndex, int tailIndex) {
        ostringstream  lastRes;
        if(startIndex == tailIndex-1) {
            lastRes << nums[startIndex];
        } else {
            lastRes << nums[startIndex] << "->" << nums[tailIndex-1];
        }

        return lastRes.str();
    }
};