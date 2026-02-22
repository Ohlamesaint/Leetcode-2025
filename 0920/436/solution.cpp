#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        // start j >= end i and minimized
        map<int, int> startToIndex;
        for(int i=0; i<intervals.size(); i++) {
            startToIndex[intervals[i][0]] = i;
        }

        vector<int> res;
        res.reserve(intervals.size());
        for(const auto& interval: intervals) {
            const auto& lowerBound = startToIndex.lower_bound(interval[1]);
            res.emplace_back(lowerBound == startToIndex.end() ? -1 : startToIndex.lower_bound(interval[1])->second);
        }
        return res;
    }
};