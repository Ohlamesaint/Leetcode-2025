#include <stack>
#include <utility>

using namespace std;

class MinStack {
    stack<pair<int, int>> main;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(main.empty()) {
            main.push({val, val});
        } else {
            main.push({val, min(val, main.top().second)});
        } 
        
        
    }
    
    void pop() {
        main.pop();
    }
    
    int top() {
        return main.top().first;
    }
    
    int getMin() {
        return main.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */