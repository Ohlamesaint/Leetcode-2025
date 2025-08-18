#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    unordered_map<Node*, Node*> origin2clone;
public:
    Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL;
        if(origin2clone.find(node)!=origin2clone.end()) return origin2clone[node];
        Node* clone = new Node(node->val);
        origin2clone[node] = clone;
        vector<Node*> clonedNeighbors;
        for(const auto neighbor: node->neighbors) {
            clonedNeighbors.push_back(cloneGraph(neighbor));
        }
        clone->neighbors = clonedNeighbors;
        
        return clone;
    }
};

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};