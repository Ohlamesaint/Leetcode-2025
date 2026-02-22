#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class TimeMap {
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mem[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        if(mem.find(key) == mem.end()) {
            return "";
        }

        const auto& timestamps = mem[key];
        int left = 0, right = timestamps.size();
        while(left<right) {
            int mid = left + (right-left)/2;
            if(timestamps[mid].second<=timestamp) {
                left = mid+1;
            } else {
                right = mid;
            }
        }
        return left == 0 ? "" : timestamps[left-1].first;

    }

private:

    unordered_map<string, vector<pair<string, int>>> mem;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */