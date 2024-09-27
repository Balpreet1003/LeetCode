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
    // Function to reverse elements between index i and j in vector a
    void rev(vector<ListNode*>& a, int i, int j) {
        while (i < j) swap(a[i++], a[j--]);
    }
    
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || !head->next || k == 1) return head; // Base cases
        
        vector<ListNode*> a;
        
        // Store all nodes in the vector
        while (head) {
            a.push_back(head);
            head = head->next;
        }
        
        // Reverse every group of size k
        for (int i = 0; i + k <= a.size(); i += k) {
            rev(a, i, i + k - 1);
        }
        
        // Rebuild the linked list from the modified vector
        head = a[0];
        for (int i = 1; i < a.size(); i++) {
            a[i - 1]->next = a[i];
        }
        a[a.size() - 1]->next = nullptr; // Ensure the last node points to null
        
        return head;
    }
};