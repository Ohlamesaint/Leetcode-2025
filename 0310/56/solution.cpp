#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(), [](const auto & i1, const auto & i2){
            if(i1[0]==i2[0]) {
                return i1[1] < i2[1];
            }
            return i1[0]<i2[0];
        });
        
        int currentEnd = intervals[0][1];
        int currentStart = intervals[0][0];
        vector<vector<int>> answer ({});
        for(int i=1; i<intervals.size(); i++) {
            if(currentEnd < intervals[i][0]) {
                answer.push_back({currentStart, currentEnd});
                currentStart = intervals[i][0];
                currentEnd = intervals[i][1];
            } else {
                currentEnd = max(intervals[i][1], currentEnd);
            }
        }
        answer.push_back({currentStart, currentEnd});

        return answer;


    }
};