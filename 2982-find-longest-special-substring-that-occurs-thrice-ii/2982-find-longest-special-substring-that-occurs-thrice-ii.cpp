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
        vector<vector<int>>a(26,vector<int>(3,-1));
        int n=s.length();
        int x=1;
        char ch=s[0];
        updateVector(a,(int)(ch-'a'),x);
        bool flag=false;
        for(int i=1;i<n;i++){
            int y=(int)(ch-'a');
            if(s[i]==ch){
                x++;
                updateVector(a,y,x);
            }
            else{
                flag=true;
                ch=s[i];
                x=1;
                updateVector(a,y,x);
            }
        }
        if(flag)updateVector(a,(int)(ch-'a'),x);
        for(int i=0;i<26;i++){
            cout<<a[i][0]<<" "<<a[i][1]<<" "<<a[i][2]<<endl;
        }
        int ans=-1;
        for(auto i:a){
            int y=min(i[0],min(i[1],i[2]));
            ans=max(ans,y);
        }
        return ans;
    }
};