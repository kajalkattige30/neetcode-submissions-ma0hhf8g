/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:

    void createCopyNodes(Node* head) {
        Node* temp = head;
        while(temp != NULL) {
            Node* copyNode = new Node(temp->val);
            copyNode->next = temp->next;
            temp->next = copyNode;
            temp = temp->next->next;
        }
    }

    void connectRandomPointers(Node* head) {
        Node* temp = head;
        while(temp != NULL) {
            Node* copyNode = temp->next;
            if(temp->random != NULL) {
                copyNode->random = temp->random->next;
            }
            else{
                copyNode->random = NULL;
            }
            temp = temp->next->next;
        }
    }

    Node* getDeepCopy(Node* head) {
        Node* temp = head;
        Node* dNode = new Node(-1);
        Node* res = dNode;
        while(temp != NULL) {
            res->next = temp->next;
            temp->next = temp->next->next;
            res = res->next;
            temp = temp->next;
        }
        return dNode->next;
    }

    Node* copyRandomList(Node* head) {
        // 1. create copy nodes
        createCopyNodes(head);
        // 2. connect random pointers
        connectRandomPointers(head);
        // 3. connect next pointers
        Node* res = getDeepCopy(head);
        return res;
    }
};
