#include <vector>
#include <unordered_map>
#include <cstdlib> // for rand
using namespace std;

class RandomizedSet {
    vector<int> num_list;
    unordered_map<int, int> num_2_index;
public:
    RandomizedSet() {        
    }
    
    bool insert(int val) {
        if(num_2_index.find(val) != num_2_index.end()) {
            return false;
        }
        num_list.push_back(val); 
        num_2_index[val] = num_list.size()-1;
        
        return true;
    }
    
    bool remove(int val) {
        if(num_2_index.find(val) == num_2_index.end()) {
            return false;
        }

        int index = num_2_index[val];
        num_2_index[num_list.back()] = index;
        swap(num_list.back(), num_list[index]);
        num_list.pop_back();
        num_2_index.erase(val);

        return true;
    }
    
    int getRandom() {
        int size = num_list.size();
        return num_list[rand() % size];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */