#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b){
            return a[0] < b[0];
        });
        vector<vector<int>> res;
        int start = intervals[0][0];
        int end = intervals[0][1];
        for(const auto& interval: intervals) {
            if(end>=interval[0]) {
                end = max(end, interval[1]);
            } else {
                res.push_back({start, end});
                start = interval[0];
                end = interval[1];
            }
        }
        res.push_back({start, end});
        return res;
    }
};