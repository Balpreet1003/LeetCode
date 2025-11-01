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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        sort(nums.begin(), nums.end());
        ListNode* node=head, *prev=NULL;
        while(node){
            if(binary_search(nums.begin(), nums.end(), node->val)){
                if(node==head){
                    head=node->next;
                    node->next=NULL;
                    node=head;
                }
                else{
                    prev->next=node->next;
                    node->next=NULL;
                    node=prev->next;
                }
            }
            else{
                prev=node;
                node=node->next;
            }
        }
        return head;
    }
};