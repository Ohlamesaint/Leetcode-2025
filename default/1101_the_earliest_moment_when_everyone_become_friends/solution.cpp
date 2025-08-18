#include <vector>

using namespace std;

class Solution {
    vector<int> root, rank;
public:
    int earliestAcq(vector<vector<int>>& logs, int n) {
        
        sort(logs.begin(), logs.end(), [](const auto& v1, const auto& v2) {return v1[0]<v2[0];});

        root.resize(n);
        rank.resize(n);

        for(int i=0; i<n; i++) {
            root[i] = i;
        }

        for(auto log: logs) {
            if(unionByRank(log[1], log[2])) n--;
            if(n==1) return log[0];
        }
        return -1;
    }

private:
    bool unionByRank(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if(rootX==rootY) return false;
        if(rank[rootX]>rank[rootY]) root[rootY] = rootX;
        else if(rank[rootX]<rank[rootY]) root[rootX] = rootY;
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