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
    bool hasCycle(ListNode* head) {
        if(head == nullptr || head->next == nullptr || head->next->next == nullptr) {
            return false;
        }
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (true) {
            if (slow == fast) {
                return true;
            }
            if (slow == nullptr || fast == nullptr) {
                return false;
            }
            if (fast->next == nullptr) {
                return false;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return false;
    }
};
