#include <vector>
#include <utility>

using namespace std;

class SnapshotArray {
    vector<vector<pair<int, int>>> arr;
    int snap_id = 0;
public:
    SnapshotArray(int length) {
        arr.resize(length, {{0, 0}});
    }
    
    void set(int index, int val) {
        arr[index].push_back({this->snap_id, val});
    }
    
    int snap() {
        this->snap_id++;
        return this->snap_id-1;
    }
    
    int get(int index, int snap_id) {
        auto& store = arr[index];
        int left = 0, right = store.size();
        while(left<right) {
            int mid = left + (right-left)/2;
            if(store[mid].first<=snap_id) {
                left = mid+1;
            } else {
                right = mid;
            }
        }
        left--;
        return store[left].second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */