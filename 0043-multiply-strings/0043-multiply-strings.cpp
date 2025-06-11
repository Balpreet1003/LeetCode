class Solution {
    string sum_string(string& s1,string& s2,int k){
        int n=s1.length(), m=s2.length();
        int i=n-1-k, j=m-1, carry=0;
        string ans="";

        for(int l=n-1; l>i; l--){
            ans = s1[l] + ans;
        }

        while(i>=0 && j>=0){
            int x=s1[i]-'0', y=s2[j]-'0';
            int sum=x+y+carry;
            carry=sum/10;
            ans=to_string(sum%10)+ans;
            i--; j--;
        }
        while(j>=0){
            int y=s2[j]-'0';
            int sum=y+carry;
            carry=sum/10;
            ans=to_string(sum%10)+ans;
            j--;
        }
        while(i>=0){
            int x=s1[i]-'0';
            int sum=x+carry;
            carry=sum/10;
            ans=to_string(sum%10)+ans;
            i--;
        }
        if(carry)
            ans = to_string(carry) + ans;

        return ans;
    }

public:
    string multiply(string num1, string num2) {
        if(num1=="0" || num2=="0") return "0";

        string ans="";
        int n=num2.length(), m=num1.size(), k=0;

        for(int i=n-1; i>=0; i--){
            int carry=0;
            string s1="";
            int x=num2[i]-'0';

            for(int j=m-1; j>=0; j--){
                int y=num1[j]-'0';
                int prod = (x*y) + carry;
                carry = prod / 10;
                s1 = to_string(prod % 10) + s1;
            }
            if(carry)
                s1 = to_string(carry) + s1;

            if(ans=="")
                ans = s1;
            else
                ans = sum_string(ans, s1, k);

            k++;
        }

        int i=0;
        while(i<ans.size() && ans[i]=='0') i++;
        if(i == ans.size()) return "0";

        return ans.substr(i);
    }
};