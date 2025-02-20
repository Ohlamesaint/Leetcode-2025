#include <vector>

using namespace std;

class Solution {

    vector<int> root, rank;
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size()!=n-1) return false;
        
        root.resize(n);
        rank.resize(n);

        for(int i=0; i<n; i++) {
            root[i] = i;
            rank[i] = 0;
        }
        
        for(auto edge: edges) {
            if(!unionByRank(edge[0], edge[1])) return false;
        }
        return true;

        
    }

private:

    bool unionByRank(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if(rootX==rootY) return false;
        if(rank[rootX]>rank[rootY]) root[rootY] = rootX;
        else if(rank[rootY]>rank[rootX]) root[rootX] = rootY;
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