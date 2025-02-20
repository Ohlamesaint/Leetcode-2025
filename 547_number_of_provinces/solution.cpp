#include <vector>

using namespace std;

class Solution {

private:
    vector<int> root, rank;

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int circleNum = isConnected.size();
        root.resize(isConnected.size());
        rank.resize(isConnected.size());

        for(int i=0; i<isConnected.size(); i++) {
            root[i] = i;
            rank[i] = 0;
        }
        
        int ans = circleNum;
        for(int i=0; i<circleNum; i++) {
            for(int j=i+1; j<circleNum; j++) {
                if(isConnected[i][j] && unionByRank(i, j)) {
                    ans--;
                }
            }
        }
        return ans;
    }

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