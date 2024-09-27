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
    ListNode* rotateRight(ListNode* head, int k) {
        if(k==0 || !head || !head->next)return head;
        int n=0;
        ListNode*node=head;
        while(node){
            node=node->next;
            n++;
        }
        int i=1;
        if(n>k)k=n-k;
        else if(n==k)return head;
        else k=n-(k%n);
        if(n==k)return head;
        node=head;
        ListNode*head1=NULL;
        while(node){
            ListNode*temp=node;
            if(!node->next){
                node->next=head;
                break;
            }
            node=node->next;
            if(i==k){
                head1=temp->next;
                temp->next=NULL;
            }
            i++;
        }
        return head1;
    }
};