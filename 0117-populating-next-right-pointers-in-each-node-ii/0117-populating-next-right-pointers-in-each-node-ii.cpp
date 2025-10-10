/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root)
            return root;
        unordered_map<int, vector<Node*>>m;
        queue<pair<Node*, int>>q;
        q.push({root, 0});
        while(!q.empty()){
            auto [node, level]=q.front(); q.pop();
            if(m.count(level)){
                m[level][m[level].size()-1]->next=node;
            }
            m[level].push_back(node);
            if(node->left)
                q.push({node->left, level+1});
            if(node->right)
                q.push({node->right, level+1});
        }
        // for(auto x:m){
        //     cout<<x.first<<" -> ";
        //     for(auto y:x.second){
        //         cout<<y->val<<" ";
        //     }
        //     cout<<endl;
        // }
        return root;
    }
};