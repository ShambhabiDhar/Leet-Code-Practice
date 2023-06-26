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
    int getLength(ListNode* head) {
        int length = 0;
        ListNode* curr = head;
        while (curr != nullptr) {
            length++;
            curr = curr->next;
        }
        return length;
    }
    
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr || k == 0) {
            return head;
        }
        
        int length = getLength(head);
        k %= length; // reduce k to the smallest positive value
        
        if (k == 0) {
            return head; // no rotation needed
        }
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        // Move the fast pointer k positions ahead
        for (int i = 0; i < k; i++) {
            fast = fast->next;
        }
        
        // Move both slow and fast pointers until fast reaches the last node
        while (fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
        
        // Break the list and rotate
        ListNode* newHead = slow->next;
        slow->next = nullptr;
        fast->next = head;
        
        return newHead;
    }
};
