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
    ListNode* middleNode(ListNode* head) {
        ListNode *slow=head, *fast=head;
        while(fast && fast->next){
            slow=slow->next; // incrementing slow pointer by 1
            fast=fast->next->next; // incrementing fast pointer by 2
            // so when fast will be at the end of LL , slow will be at the middle 
        }
        return slow;
    }
};