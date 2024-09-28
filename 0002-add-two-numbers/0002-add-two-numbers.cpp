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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = NULL;
        ListNode* temp = NULL;
        int sum, rema = 0;
        
        while (l1 != NULL || l2 != NULL || rema != 0) {
            sum = rema;
            if (l1 != NULL) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != NULL) {
                sum += l2->val;
                l2 = l2->next;
            }
            rema = sum / 10;
            sum %= 10;
            
            ListNode* newNode = new ListNode(sum);
            if (ans == NULL) {
                ans = newNode;
                temp = ans;
            } else {
                temp->next = newNode;
                temp = temp->next;
            }
        }
        return ans;
    }
};