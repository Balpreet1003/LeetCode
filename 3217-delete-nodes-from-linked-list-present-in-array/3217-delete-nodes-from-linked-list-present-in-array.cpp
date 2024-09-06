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
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        unordered_map<int, bool> mp;
        for (int i : nums) {
            mp[i] = true;
        }

        ListNode* n = head;
        ListNode* prev = NULL;

        while (n != NULL) {
            if (mp[n->val]) {
                if (n == head) {
                    ListNode* temp = n->next;
                    n->next = NULL;
                    head = temp;
                    n = head;
                } else {
                    prev->next = n->next;
                    n->next = NULL;
                    n = prev->next;
                }
            } else {
                prev = n;
                n = n->next;
            }
        }

        return head;
    }
};