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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy=new ListNode(0,head);
        ListNode* groupprev=dummy;
        while(groupprev){
            ListNode* kth=getkth(groupprev,k);
            if(!kth) break;
            ListNode* groupnext=kth->next;
            ListNode* prev=kth->next;
            ListNode* curr=groupprev->next;
            while(curr!=groupnext){
                ListNode* tmp=curr->next;
                curr->next=prev;
                prev=curr;
                curr=tmp;
            }
            ListNode* tmp=groupprev->next;
            groupprev->next=kth;
            groupprev=tmp;
        }
        return dummy->next;
    }
    private:
    ListNode* getkth(ListNode* curr, int k) {
        while (curr && k > 0) {
            curr = curr->next;
            k--;
        }
        return curr;
    }
};
