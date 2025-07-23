class TriesNode {
public:
    char val;
    int ind;
    TriesNode* children[26];

    TriesNode(char val) {
        this->val = val;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        ind = -1;
    }
};
class Solution {
    vector<vector<int>>ans;
    class Tries{
        TriesNode* root;
        vector<vector<int>>& ans;
        void insertUtil(TriesNode* root, string& s,int& indx,int i){
            if(i>=s.length()){
                root->ind=indx;
                return ;
            }
            TriesNode* child;
            int index=s[i]-'a';
            if(root->children[index]){
                child = root->children[index];
            }
            else {
                child = new TriesNode(s[i]);
                root->children[index] = child;
            }
            insertUtil(child, s, indx, i+1);
        }
        bool is_palindrom(string s,int i,int j){
            while(i<j){
                if(s[i]!=s[j]){
                    return false;
                }
                i++;j--;
            }
            return true;
        }
        void search_helper(TriesNode* node, int& indx, string s){
            if(node->ind!=-1){
                if(is_palindrom(s,0,s.length()-1) && indx!=node->ind){
                    ans.push_back({indx,node->ind});
                }
            }
            for(int i=0;i<26;i++){
                if(node->children[i]){
                    search_helper(node->children[i],indx,s+char('a'+i));
                }
            }
        }
    public:
        Tries(vector<vector<int>>& ansRef) : root(new TriesNode('\0')), ans(ansRef) {}
        void insert(string word,int indx){
            reverse(word.begin(),word.end());
            insertUtil(root,word,indx,0);
        }
        void search(string& word,int indx){
            TriesNode* node = root;
            for(int i=0;i<word.length();i++){
                int index = word[i] - 'a';
                if(node->ind!=-1){
                    if(is_palindrom(word, i, word.length()-1) && indx!=node->ind){
                        ans.push_back({indx, node->ind});
                    }
                }
                if(node->children[index]){
                    node=node->children[index];
                }
                else return ;
            }
            search_helper(node,indx,"");
        }
    };
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        Tries t(ans);
        for(int i=0;i<words.size();i++){
            t.insert(words[i],i);
        }
        for(int i=0;i<words.size();i++){
            t.search(words[i],i);
        }
        return ans;
    }
};