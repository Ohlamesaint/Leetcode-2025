#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int index = m+n-1;
        m--;
        n--;
        while(index>=0) {
            if(n>=0 && m>=0) {
                if(nums1[m] >= nums2[n]) {
                    nums1[index] = nums1[m];
                    m--;
                } else {
                    nums1[index] = nums2[n];
                    n--;
                }
            } else if(n>=0) {
                nums1[index] = nums2[n];
                n--;
            } else break;
            index--;
        }
    }
};