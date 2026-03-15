class Solution {
    unordered_map<long long, pair<long long, long long>> mp;

    int solve(TreeNode* root){
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});
        int ans=0;

        while(!q.empty()){
            int len=q.size();
            int ind=q.front().second;
            int l=0, r=0;
            for(int i=0;i<len;i++){
                auto [node, x] = q.front();
                q.pop();

                long long curr=x-ind;
                if(i==0) l=curr;
                if(i==len-1) r=curr;
                if(node->left)
                    q.push({node->left, curr*2});
                if(node->right)
                    q.push({node->right, curr*2+1});
            }
            ans=max(ans, r-l+1);
        }
        return ans;
    }

public:
    int widthOfBinaryTree(TreeNode* root) {
        return solve(root);
    }
};