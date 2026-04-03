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
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*> oldtocopy;
        oldtocopy[NULL]=NULL;
        Node* cur=head;
        while(cur!=NULL){
            Node* copy=new Node(cur->val);
            oldtocopy[cur]=copy;
            cur=cur->next;
        }
        cur=head;
        while(cur!=NULL){
            Node* copy=oldtocopy[cur];
            copy->next=oldtocopy[cur->next];
            copy->random=oldtocopy[cur->random];
            cur=cur->next;
        }
        return oldtocopy[head];
    }
};
