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
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        if(!head) return NULL;
        Node*node=head;
        while(node){
            Node*temp=new Node(node->val);
            temp->next=node->next;
            node->next=temp;
            node=temp->next;
        }
        node=head;
        while(node){
            if(node->random)
                node->next->random=node->random->next;
            node=node->next->next;
        }
        node=head;
        head=node->next;
        while(node){
            Node*temp=node->next;
            node->next=node->next->next;
            node=temp->next;
            if(temp->next)
                temp->next=node->next;
        }
        return head;
    }
};