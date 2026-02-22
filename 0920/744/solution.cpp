#include <vector>

using namespace std;

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int left = 0, right = letters.size();
        while(left<right) {
            int mid = (left+right)/2;
            if(letters[mid]<=target) {
                left = mid+1;
            } else {
                right = mid;
            }
        }
        while(left < letters.size() && letters[left] == target) left++;
        return left == letters.size() ? letters[0] : letters[left];
    }
};