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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {

        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);

        ListNode*temp=head;
        while(temp->next){
            int x=__gcd(temp->val,temp->next->val);
            ListNode*temp1=new ListNode(x);
            temp1->next=temp->next;
            temp->next=temp1;
            temp=temp1->next;
        }
        return head;
    }
};