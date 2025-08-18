#include <vector>
#include <unordered_set>
#include <iterator>

using namespace std;

class Solution {

    

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<bool> inStack(graph.size());
        vector<int> isVisited(graph.size());
        
        for(int i=0; i<graph.size(); i++) {
            if(isVisited[i]==0) {
                inStack[i] = true;
                dfs(graph, i, inStack, isVisited);
                inStack[i] = false;
            }
        }
        vector<int> ans;
        for(int i=0; i<isVisited.size(); i++) {
            if(isVisited[i]==1) {
                ans.push_back(i);
            }
        }
        return ans;

    }

private:
    void dfs(vector<vector<int>>& graph, int current, vector<bool>& inStack, vector<int>& isVisited) {
        for(int adj: graph[current]) {
            if(inStack[adj] || isVisited[adj] == -1) {
                isVisited[current] = -1;
                return;
            }
            else if (isVisited[adj] == 1) continue;
            else {
                inStack[adj] = true;
                dfs(graph, adj, inStack, isVisited);
                inStack[adj] = false;
                if(isVisited[adj] == -1) {
                    isVisited[current] = -1;
                    return;
                }
            }
        }
        isVisited[current] = 1;
    }
};