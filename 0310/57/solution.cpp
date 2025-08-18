#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if(intervals.size()==0) return {newInterval};
        vector<vector<int>> res ({});
        int i=0;
        while(i<intervals.size() && intervals[i][1]<newInterval[0]) {
            res.push_back(intervals[i]);
            i++;
        }
        
        int start = newInterval[0];
        int end = newInterval[1];
        while(i<intervals.size() && intervals[i][0]<=end) {
            end = max(intervals[i][1], end);
            start = min(intervals[i][0], start);
            i++;
        }
        res.push_back({start, end});

        while(i<intervals.size()) {
            res.push_back(intervals[i]);
            i++;
        }
        return res; 
    }
};