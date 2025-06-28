class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        vector<int>sum(n,1);
        for(int i=1;i<n;i++){
            if(ratings[i]>ratings[i-1]){
                sum[i]=sum[i-1]+1;
            }
            // else if(ratings[i]==ratings[i-1]){
            //     sum[i]=sum[i-1];
            // }
        }
        for(int i:sum){
            cout<<i<<" ";
        }cout<<endl;
        for(int i=n-2;i>=0;i--){
            if(ratings[i]>ratings[i+1]){
                if(sum[i]<=sum[i+1]){
                    sum[i]=sum[i+1]+1;
                }
                // else if(ratings[i]==ratings[i+1]){
                //     sum[i]=sum[i+1];
                // }
            }
        }
        for(int i:sum){
            cout<<i<<" ";
        }cout<<endl;
        return accumulate(sum.begin(),sum.end(),0);
    }
};