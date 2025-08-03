/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* prev=NULL;
        while(node->next){
            prev=node;
            swap(node->val,node->next->val);
            node=node->next;
        }
        prev->next=NULL;
    }
};