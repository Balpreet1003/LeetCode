class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        int i=0,j=0,n=a.size()+b.size(),k=0;
        int x=n/2,y=(n/2)-1;
        int ele1=-1,ele2=-1;
        while(i<a.size() && j<b.size()){
            if(a[i]<b[j]){
                if(k==x)ele1=a[i];
                if(k==y)ele2=a[i];
                i++;
            }
            else{
                if(k==x)ele1=b[j];
                if(k==y)ele2=b[j];
                j++;
            }
            k++;
        }
        while(i<a.size()){
            if(k==x)ele1=a[i];
            if(k==y)ele2=a[i];
            i++;
            k++;
        }
        while(j<b.size()){
            if(k==x)ele1=b[j];
            if(k==y)ele2=b[j];
            j++;
            k++;
        }
        if(n&1)return (double)ele1;
        return (double)((double)ele1+ele2)/2.0;
    }
};