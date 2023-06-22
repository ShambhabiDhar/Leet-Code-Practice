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
    ListNode* reverse(ListNode* ptr) {
        ListNode* pre=NULL;
        ListNode* nex=NULL;
        while(ptr!=NULL) {
            nex = ptr->next;
            ptr->next = pre;
            pre=ptr;
            ptr=nex;
        }
        return pre;
    }
    
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return true;

        ListNode* slow = head;
        ListNode* fast = head;

        // Move fast pointer by two steps and slow pointer by one step
        // When fast reaches the end, slow will be at the middle
        while (fast->next != nullptr && fast->next->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }

        // Reverse the second half of the list starting from slow->next
        ListNode* secondHalf = reverse(slow->next);
        slow->next = nullptr;  // Break the link between the first and second halves

        // Compare the elements of the first and reversed second halves
        ListNode* firstHalf = head;
        ListNode* secondHalfPtr = secondHalf;

        bool isPalindrome = true;
        while (secondHalfPtr != nullptr) {
            if (firstHalf->val != secondHalfPtr->val) {
                isPalindrome = false;
                break;
            }
            firstHalf = firstHalf->next;
            secondHalfPtr = secondHalfPtr->next;
        }

        // Restore the original list by reversing the second half again
        slow->next = reverse(secondHalf);

        return isPalindrome;
    }
};