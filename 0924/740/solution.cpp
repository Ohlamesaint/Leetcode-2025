#include <vector>
#include <unordered_map>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int, int> numToSum;
        int maxNum = INT_MIN, minNum = INT_MAX;
        for(const auto& num: nums) {
            numToSum[num]+=num;
            maxNum = max(maxNum, num);
            minNum = min(minNum, num);
        }

        int prevMax = 0;
        int prevPrevMax = 0;
        for(int i=minNum; i<=maxNum; i++) {
            int temp = max(numToSum[i]+prevPrevMax, prevMax);
            prevPrevMax = prevMax;
            prevMax = temp;
        }
        return prevMax;
    }
};