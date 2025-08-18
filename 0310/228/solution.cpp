#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int start = 0;
        vector<string> answer;
        if(nums.size()==0) return {};
        for(int i=1; i<nums.size(); i++) {
            if(nums[i]!=nums[i-1]+1) {
                answer.push_back(generateRange(nums[start], nums[i-1]));
                start = i;
            }
        }
        answer.push_back(generateRange(nums[start], nums.back()));
        return answer;
    }
private:
    string generateRange(int start, int end) {
        if(start == end) return generateRange(start);
        return to_string(start)+"->"+to_string(end);
    }

    string generateRange(int start) {
        return to_string(start);
    }
};