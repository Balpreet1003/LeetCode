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
    ListNode* reverse(ListNode* head){
        ListNode* node=head, *prev=NULL;
        while(node){
            ListNode* temp=node->next;
            head=node;
            node->next=prev;
            prev=node;
            node=temp;
        }
        return head;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1=reverse(l1);
        l2=reverse(l2);
        int rem=0;
        ListNode* dummy=new ListNode(-1), *node, *prev;
        prev=dummy;
        while(l1 && l2){
            int sum=l1->val+l2->val+rem;
            rem=sum/10;
            node=new ListNode(sum%10);
            prev->next=node;
            prev=node;
            l1=l1->next;
            l2=l2->next;
        }
        while(l1){
            int sum=l1->val+rem;
            rem=sum/10;
            node=new ListNode(sum%10);
            prev->next=node;
            prev=node;
            l1=l1->next;
        }
        while(l2){
            int sum=l2->val+rem;
            rem=sum/10;
            node=new ListNode(sum%10);
            prev->next=node;
            prev=node;
            l2=l2->next;
        }
        if(rem!=0){
            node=new ListNode(rem);
            prev->next=node;
            prev=node;
        }
        return reverse(dummy->next);
    }
};