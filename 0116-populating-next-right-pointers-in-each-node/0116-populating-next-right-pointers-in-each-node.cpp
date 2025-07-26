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
    unordered_map<int,queue<Node*>>m;
    void connect_next(Node* root,int h){
        if(!root){
            return;
        }
        connect_next(root->right,h+1);
        root->next=(m[h].empty()) ? NULL : m[h].front();
        if(!m[h].empty()){
            m[h].pop();
        }
        connect_next(root->left,h+1);
        m[h].push(root);
    }
public:
    Node* connect(Node* root) {
        connect_next(root,0);
        return root;
    }
};