#include <unordered_map>


using namespace std;


class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr) return nullptr;

        unordered_map<Node*, Node*> origin2Copy;
        Node dummy(-1);
        dummy.next = head;
        Node* runner = dummy.next;
        while(runner != nullptr) {
            Node* clone = new Node(runner->val);
            clone ->next = runner ->next;
            runner->next = clone;
            runner = runner ->next->next;
        }

        runner = dummy.next;
        while(runner != nullptr) {
            if(runner->random != nullptr) {
                // handle random
                runner->next->random = runner->random != nullptr ? runner->random->next : nullptr;  
            }
            runner = runner ->next ->next;
        }

        runner = dummy.next;
        Node* new_runner = runner->next;
        Node* new_head = runner->next;
        while(runner != nullptr) {
            // handle next
            runner->next = runner->next->next;
            new_runner->next = (new_runner->next != nullptr) ? new_runner->next->next : nullptr;
            runner = runner->next;
            new_runner = new_runner->next;
        }
        return new_head;
    }
};

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};