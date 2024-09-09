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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);

        vector<vector<int>>ans(m,vector<int>(n,-1));
        ans[0][0]=head->val;
        ListNode* temp=head->next;
        int a=0,b=0,c=m-1,d=n-1,i=0,j=1;
        while(a<=c && b<=d && temp){
            for(;j<=d;j++){
                if(temp){
                    ans[i][j]=temp->val;
                    temp=temp->next;
                }
            }
            a++;
            i=a;j=d;
            for(;i<=c;i++){
                if(temp){
                    ans[i][j]=temp->val;
                    temp=temp->next;
                }
            }
            d--;
            i=c;j=d;
            for(;j>=b;j--){
                if(temp){
                    ans[i][j]=temp->val;
                    temp=temp->next;
                }
            }
            c--;
            i=c;j=b;
            for(;i>=a;i--){
                if(temp){
                    ans[i][j]=temp->val;
                    temp=temp->next;
                }
            }
            b++;
            i=a;j=b;
        }
        return ans;
    }
};