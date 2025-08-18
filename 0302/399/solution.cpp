#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
    unordered_map<std::string, int> rank, productToParent;
    unordered_map<std::string, std::string> root;
    unordered_set<std::string> numbers;
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        for(const auto &equation: equations) {
            numbers.insert(equation[0]);
            numbers.insert(equation[1]);
        }
        
        for(const auto& number: numbers) {
            rank[number] = 1;
            root[number] = number;
            productToParent[number] = 1;
        }

        for(int i=0; i<equations.size(); i++) {
            unionByRank(equations[i][0], equations[i][1], values[i]);
        }
        

    }

    void unionByRank(string x, string y, double defaultProduct) {
        string rootX = find(x);
        string rootY = find(y);
        double xToRoot = calculateProductToRoot(x, 1);
        double yToRoot = calculateProductToRoot(y, 1);
        if(rootX==rootY) return;
        double rootY2rootX = calculateProductToRoot(rootY, 1) / calculateProductToRoot(rootX, 1);
        if(rank[rootX]>rank[rootY]) {
            root[rootY] = rootX;
            productToParent[rootY] = rootY2rootX;
        }
        else if(rank[rootY]>rank[rootX]) {
            root[rootX] = rootY;
            productToParent[rootX] = 1/rootY2rootX;

        }
        else {
            rank[rootX] ++;
            root[rootY] = rootX;
            productToParent[rootY] = rootY2rootX;
        }
    }

    double calculateProductToRoot(string x, double currentProduct) {
        if(root[x] == x) return currentProduct;
        return calculateProductToRoot(root[x], currentProduct*productToParent[x]);
    }

    string find(string x) {
        if(root[x] == x) return x;
        return root[x] = find(root[x]);
    }
};