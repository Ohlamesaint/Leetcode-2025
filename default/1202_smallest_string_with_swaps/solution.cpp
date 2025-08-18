#include <vector>
#include <string>
#include <unordered_map>
#include <set>

using namespace std;

class Solution {

    vector<int> rank, root;

public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int len = s.length();
        int group = len;
        rank.resize(len);
        root.resize(len);
        for(int i=0; i<len; i++) {
            rank[i] = 1;
            root[i] = i;
        }

        for(const auto& pair: pairs) {
            if(unionByRank(pair[0], pair[1])) group--;
        }
        unordered_map<int, string> group2str;
        for(int i=0; i<len; i++) {
            if(group2str[root[i]].empty()) group2str[root[i]] = string("");
            group2str[root[i]].push_back(s[i]);
        }

        for(auto& pair: group2str) {
            sort(pair.second.begin(), pair.second.end());
        }
        vector<int> group2Index(group, 0);
        string ans("");
        for(int i=0; i<len; i++) {
            ans.push_back(group2str[root[i]][group2Index[root[i]]]);
            group2Index[root[i]]++;
        }
        return ans;

    }

    bool unionByRank(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if(rootX == rootY) return false;
        if(rank[rootY] < rank[rootX]) root[rootY] = rootX;
        else if(rank[rootX] < rank[rootY]) root[rootX] = rootY;
        else {
            root[rootY] = rootX;
            rank[rootX]++;
        }
        return true;
    }

    int find(int x) {
        if(root[x] == x) return x;
        return root[x] = find(root[x]);
    }

};