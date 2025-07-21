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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    TreeNode* solve(vector<int>&a, int i,int j){
        if(i>j){
            return NULL;
        }
        int mid=(i+j)/2;
        TreeNode* node=new TreeNode(a[mid]);
        node->left=solve(a,i,mid-1);
        node->right=solve(a,mid+1,j);
        return node;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int>a;
        while(head){
            a.push_back(head->val);
            head=head->next;
        }
        return solve(a,0,a.size()-1);
    }
};