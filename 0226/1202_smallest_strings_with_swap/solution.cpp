#include <vector>
#include <string>

using namespace std;

class Solution {

    vector<int> rank, root;
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        rank.resize(s.size(), 0);
        root.resize(s.size());

        for(int i = 0; i < s.size(); i++) {
            root[i] = i;
        }

        
    }

    void unionByRank(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if(rank[rootX] > rank[rootY]) {
            root[rootY] = rootX;
        } else if(rank[rootX] < rank[rootY]) {
            root[rootX] = rootY;
        } else {
            root[rootX] = rootY;
            rank[rootY]++;
        }
    }

    int find(int x) {
        if(root[x] == x) return x;
        return root[x] = find(root[x]);;
    }
};