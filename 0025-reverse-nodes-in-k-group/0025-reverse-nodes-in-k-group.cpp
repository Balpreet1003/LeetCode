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
    int get_len(ListNode* head){
        ListNode* node=head;
        int ans=0;
        while(node){
            node=node->next;
            ans++;
        }
        return ans;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1) {
            return head;
        }
        int len=get_len(head);
        int t=len/k;
        ListNode* node=head, *tail=NULL;
        while(t--){
            ListNode* head1=node, *prev=NULL, *tail1=node;
            int temp=k;
            while(node && temp--){
                head1=node;
                node=node->next;
                head1->next=prev;
                prev=head1;
            }
            if(tail){
                tail->next=head1;
            }
            tail=tail1;
            if(tail==head){
                head=head1;
            }
        }
        tail->next=node;
        return head;
    }
};