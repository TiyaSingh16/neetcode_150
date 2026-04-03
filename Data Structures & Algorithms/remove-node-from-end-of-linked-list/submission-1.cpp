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
    ListNode* rec(ListNode* curr, int &n){
        //&n so that the value of n gets updated every time, not just the constant value n
        if(!curr) return NULL; //reaches the actual node now
        curr->next=rec(curr->next,n);
        n--;
        if(n==0){
            return curr->next;
        }
        return curr;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        return rec(head,n);
    }
};