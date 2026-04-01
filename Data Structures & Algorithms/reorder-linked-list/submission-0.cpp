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
    ListNode* reverseList(ListNode* head) {
        ListNode* temp = head;
        ListNode* prev = nullptr;
        while(temp != nullptr) {
            ListNode* next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* newHead = slow->next;
        slow->next = nullptr;
        ListNode* revHead = reverseList(newHead);
        ListNode* p1 = head;
        ListNode* p2 = revHead;
        while(p2 != nullptr) {
            ListNode* p1N = p1->next;
            ListNode* p2N = p2->next;
            p1->next = p2;
            p2->next = p1N;
            p1 = p1N;
            p2 = p2N;
        }
    }
};
