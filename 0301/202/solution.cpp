/*
1 <= n <= 2^31 - 1
*/

#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> presented;
        int sum = n;
        while(sum != 1) {
            if(presented.count(sum)) return false;
            presented.insert(sum);
            n = sum;
            sum = 0;
            while(n!=0) {
                sum+=(n%10)*(n%10);
                n/=10;
            }
        }
        return true;
        
    }
};