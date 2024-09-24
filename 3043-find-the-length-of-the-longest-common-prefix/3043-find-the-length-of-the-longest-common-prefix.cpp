class tries{
public:
    char ch;
    tries*child[10];
    bool isTer;

    tries(char c){
        ch=c;
        for(int i=0;i<10;i++)child[i]=NULL;
        isTer=0;
    }

    void add(tries* root,string s,int i){
        if(i>=s.length()){
            isTer=1;
            return;
        }
        int ind=s[i]-'0';
        tries*c1;
        if(root->child[ind]!=NULL)c1=root->child[ind];
        else{
            c1=new tries(s[i]);
            root->child[ind]=c1;
        }
        add(c1,s,i+1);
    }
    int findPre(tries*root,string s,int i){
        if(i>=s.length() || root->child[s[i]-'0']==NULL)return 0;
        return findPre(root->child[s[i]-'0'],s,i+1)+1;
    }
};
class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        tries*root=new tries('%');
        for(int i=0;i<arr1.size();i++){
            root->add(root,to_string(arr1[i]),0);
        }
        int ans=0;
        for(int i=0;i<arr2.size();i++){
            ans=max(ans,root->findPre(root,to_string(arr2[i]),0));
        }
        return ans;
    }
};