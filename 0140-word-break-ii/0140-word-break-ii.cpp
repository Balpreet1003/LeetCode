class TrieNode{
public:
    char val;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char c){
        val=c;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        isTerminal = false;
    }
};
class Tries{
    TrieNode* root;
    void insertNodeUtil(string& word, TrieNode* root,int i){
        if(i==word.length()){
            root->isTerminal=true;
            return;
        }
        int ind=word[i]-'a';
        TrieNode* child;
        if(root->children[ind]){
            child = root->children[ind];
        }
        else{
            child = new TrieNode(word[i]);
            root->children[ind]=child;
        }
        insertNodeUtil(word, child, i+1);
    }
    bool searchUtil(string& word, TrieNode* root,int i){
        if(i==word.length()){
            return root->isTerminal;
        }
        int ind=word[i]-'a';
        TrieNode* child;
        if(root->children[ind]){
            child = root->children[ind];
        }
        else{
            return false;
        }
        return searchUtil(word, child, i+1);
    }

public:
    Tries(){
        root = new TrieNode('\0');
    }
    void insertNode(string& word){
        insertNodeUtil(word,root,0);
    }
    bool search(string word){
        return searchUtil(word,root,0);
    }
};
class Solution {
    vector<string>ans;
    Tries t;
    void solve(string& s, int i, string temp) {
        if (i >= s.length()) {
            ans.push_back(temp.substr(1));
            return;
        }
        string s1 = "";
        for (int j = i; j < s.length(); j++) {
            s1 += s[j];
            if (t.search(s1)) {
                solve(s, j + 1, temp + " " + s1);
            }
        }
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for( auto x:wordDict){
            t.insertNode(x);
        }
        solve(s,0,"");
        return ans;
    }
};