class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        while(s[i]==' ')i++;
        bool sign =0;
        if(s[i]=='+' || s[i]=='-'){
            sign=s[i]=='-';
            i++;
        }
        long long ans=0;
        while(i<s.length() && isdigit(s[i])){
            long long x=sign?ans*(-1):ans;
            if(x>INT_MAX)return INT_MAX;
            if(x<INT_MIN)return INT_MIN;
            ans=ans*10+(long long)(s[i]-'0');
            i++;
        }
        ans=sign?ans*(-1):ans;
        if(ans>INT_MAX)return INT_MAX;
        if(ans<INT_MIN)return INT_MIN;
        return ans;
    }
};