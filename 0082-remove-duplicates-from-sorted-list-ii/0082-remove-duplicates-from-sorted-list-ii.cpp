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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head)return head;
        unordered_map<int,int>m;
        ListNode* node=head;
        while(node!=NULL){
            m[node->val]++;
            node=node->next;
        }
        node=head;
        ListNode* prev=NULL, *new_head=NULL;
        while(node!=NULL){
            if(m[node->val]==1){
                if(prev==NULL){
                    new_head=node;
                }
                else{
                    prev->next=node;
                }
                prev=node;
                node=node->next;
                prev->next=NULL;
            }
            else{
                node=node->next;
            }
        }
        return new_head;
    }
};