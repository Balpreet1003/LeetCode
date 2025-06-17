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
    ListNode* partition(ListNode* head, int x) {
        if(!head || !head->next)return head;
        ListNode* h1=NULL, *h2=NULL, *node=head,*head1=NULL,*head2=NULL;

        while(node){
            if(node->val<x){
                if(h1==NULL){
                    h1=node;
                    head1=node;
                }
                else{
                    h1->next=node;
                    h1=node;
                }
            }
            else{
                if(h2==NULL){
                    h2=node;
                    head2=node;
                }
                else{
                    h2->next=node;
                    h2=node;
                }
            }
            node=node->next;
            if(h1)h1->next=NULL;
            if(h2)h2->next=NULL;
        }
        if(!head1)return head2;
        h1->next=head2;
        return head1;
    }
};