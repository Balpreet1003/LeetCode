class Solution {
public:
    int myAtoi(string s) {
        long long ans=0,i=0,sign=1;
        bool trace=true;
        while(i<s.length()){
            if(s[i]!=' ')
                break;
            i++;
        }
        if(s[i]=='-' && trace){
            sign=-1;
            i++;
            trace=false;
        }
        if(s[i]=='+' && trace)
            i++;
        while(i<s.length()){
            if(isdigit(s[i])){
                ans=ans*10+(s[i]-'0');
                if(ans>INT_MAX && sign<0)
                    return INT_MIN;
                if(ans>INT_MAX && sign>0)
                    return INT_MAX;
            }
            else
                break;
            i++;
        }
        
        ans*=sign;
        
        return ans;
    }
};