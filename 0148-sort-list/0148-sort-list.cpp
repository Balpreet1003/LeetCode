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
    static bool cmd(ListNode*a,ListNode*b){
        return a->val<b->val;
    }
public:
    ListNode* sortList(ListNode* head) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        if(!head || !head->next) return head;

        vector<ListNode*> nums;
        ListNode* current = head;
        while(current) {
            nums.push_back(current);
            current = current->next;
        }

        sort(nums.begin(),nums.end(),cmd);

        for(int i = 0; i < nums.size() - 1; i++) {
            nums[i]->next = nums[i + 1];
        }
        nums.back()->next = nullptr;
        return nums[0];
    }
};