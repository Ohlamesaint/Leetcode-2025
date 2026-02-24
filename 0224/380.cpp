#include <unordered_map>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class RandomizedSet {

    unordered_map<int, int> numToIndex;
    vector<int> nums;
public:
    RandomizedSet() {
        srand(time(NULL));
    }
    
    bool insert(int val) {
        if(numToIndex.contains(val)) {
            return false;
        } else {
            nums.push_back(val);
            numToIndex[val] = nums.size()-1;
        }
        return true;
    }
    
    bool remove(int val) {
        if(!numToIndex.contains(val)) {
            return false;
        } else {
            int last = nums.back();
            swap(nums[numToIndex[val]], nums.back());
            nums.pop_back();
            numToIndex[last] = numToIndex[val];
            numToIndex.erase(val);
        }
        return true;
    }
    
    int getRandom() {
        int size = nums.size();
        return nums[rand() % size];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */