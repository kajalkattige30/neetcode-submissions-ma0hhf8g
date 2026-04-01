/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* findKthNode(ListNode* node, int k) {
        ListNode* temp = node;
        k -= 1;
        while(temp != NULL && k > 0) {
            temp = temp->next;
            k--;
        }
        return temp;
    }

    ListNode* reverseLinkedList(ListNode* node) {
        ListNode* temp = node;
        ListNode* prev = NULL;
        while(temp != NULL) {
            ListNode* next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* prev = NULL;
        ListNode* nextNode = NULL;
        ListNode* temp = head;
    
        while(temp != NULL) {
            ListNode* kthNode = findKthNode(temp, k);
            if(kthNode == NULL) {
                if(prev) prev->next = temp;
                break;
            }
            nextNode = kthNode->next;
            kthNode->next = NULL;
            reverseLinkedList(temp);
            if(temp == head) {
                head = kthNode;
            }
            else {
                prev->next = kthNode;
            }
            prev = temp;
            temp = nextNode;
        }
        return head;
    }
};
