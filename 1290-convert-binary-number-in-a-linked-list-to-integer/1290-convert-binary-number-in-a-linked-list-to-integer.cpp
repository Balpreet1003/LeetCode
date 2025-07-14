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
    int getDecimalValue(ListNode* head) {
        ListNode *node = head, *prev = NULL;
        while (node) {
            ListNode* nxt = node->next;
            node->next = prev;
            prev = node;
            node = nxt;
            if (!node) {
                head = prev;
            }
        }
        node = head;
        int ans = 0, i = 0;
        while (node) {
            if (node->val == 1) {
                ans += (1 << i);
            }
            i++;
            node = node->next;
        }
        return ans;
    }
};