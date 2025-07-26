class Solution {
public:
    string addBinary(string a, string b) {
        int carry=0, i=a.length()-1, j=b.length()-1;
        string ans="";
        while(i>=0 && j>=0){
            int x=a[i--]-'0';
            int y=b[j--]-'0';

            int sum=x+y+carry;
            carry=sum/2;
            sum%=2;
            ans+=to_string(sum);
        }
        while(i>=0){
            int x=a[i--]-'0';
            int sum=x+carry;
            carry=sum/2;
            sum%=2;
            ans+=to_string(sum);
        }
        while(j>=0){
            int y=b[j--]-'0';
            int sum=y+carry;
            carry=sum/2;
            sum%=2;
            ans+=to_string(sum);
        }
        if(carry>0){
            ans+=to_string(carry);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};