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
    int length(ListNode *head){
        int len = 0;
        while(head){
            len++;
            head = head->next;
        }
        return len;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        int len = length(head);
        ListNode *res= new ListNode();
        res->next = head;
        ListNode *prev=res, *curr=res, *nex=res;
        while(len>=k){
            curr=prev->next;
            nex=curr->next;
            for(int i=1;i<k;i++)
            {
                curr->next=nex->next;
                nex->next=prev->next;
                prev->next=nex;
                nex=curr->next;
            }
            prev=curr;
            len-=k;
        }
        return res->next;
    }
};