class Solution {
    int getAns(vector<int>&a,int i,int mid,int j){
        int ans=0;
        int x=i,y=mid+1;
        while(x<=mid && y<=j){
            if((long long)a[x]>(long long)2*a[y]){
                ans+=(mid-x+1);
                y++;
            }
            else{
                x++;
            }
        }
        return ans;
    }
    void merge(vector<int>&a,int i,int mid,int j){
        vector<int>temp;
        int x=i,y=mid+1;
        while(x<=mid && y<=j){
            if(a[x]<=a[y]){
                temp.push_back(a[x++]);
            }
            else{
                temp.push_back(a[y++]);
            }
        }
        while(x<=mid)temp.push_back(a[x++]);
        while(y<=j)temp.push_back(a[y++]);
        
        for(int k=0;k<temp.size();k++){
            a[i++]=temp[k];
        }
    }
    int mergeSort(vector<int>&a,int i,int j){
        if(i>=j)return 0;
            
        int mid=(i+j)/2;
        int ans=0;
        ans+=mergeSort(a,i,mid);
        ans+=mergeSort(a,mid+1,j);
        
        ans+=getAns(a,i,mid,j);
        merge(a,i,mid,j);
        return ans;
    }
public:
    int reversePairs(vector<int>& arr) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        return mergeSort(arr,0,arr.size()-1);
    }
};