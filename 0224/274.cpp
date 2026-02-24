#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), [](const auto& a, const auto& b){
            return a>=b;
        });

        for(int i=0; i<citations.size(); i++) {
            if(citations[i]<=i) {
                return i;
            }
        }
        return citations.size();
    }
};