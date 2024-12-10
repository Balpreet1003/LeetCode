class Solution {
    void updateVector(vector<vector<int>>&a,int i,int&x){
        int y=min(a[i][0],min(a[i][1],a[i][2]));
        if(x<=y)return;
        if(a[i][0]==y)a[i][0]=x;
        else if(a[i][1]==y)a[i][1]=x;
        else a[i][2]=x;
    }
public:
    int maximumLength(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        vector<vector<int>>a(26,vector<int>(3,-1));
        int n=s.length();
        int x=1;
        char ch=s[0];
        updateVector(a,(int)(ch-'a'),x);
        bool flag=false;
        for(int i=1;i<n;i++){
            if(s[i]==ch){
                int y=(int)(ch-'a');
                x++;
                updateVector(a,y,x);
            }
            else{
                flag=true;
                ch=s[i];
                x=1;
                int y=(int)(ch-'a');
                updateVector(a,y,x);
            }
        }
        int ans=-1;
        for(auto i:a){
            int y=min(i[0],min(i[1],i[2]));
            ans=max(ans,y);
        }
        return ans;
    }
};