#include <vector>

using namespace std;

class Solution {
    vector<int> root, rank;
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        root.resize(n);
        rank.resize(n);

        for(int i=0; i<n; i++) {
            root[i] = i;
        }

        int componentNum = n;
        for(auto edge: edges) {
            if(unionByRank(edge[0], edge[1])) componentNum--;
        }
        return componentNum;
    }

private:

    bool unionByRank(int x, int y) {
        int rootX = findRoot(x);
        int rootY = findRoot(y);
        if(rootX==rootY) return false;
        if(rank[rootX]>rank[rootY]) root[rootY] = rootX;
        else if(rank[rootX]<rank[rootY]) root[rootX] = rootY;
        else {
            root[rootY] = rootX;
            rank[rootX]++;
        }
        return true;
    }

    int findRoot(int x) {
        if(root[x]==x)  return x;
        return root[x] = findRoot(root[x]);
    }
};