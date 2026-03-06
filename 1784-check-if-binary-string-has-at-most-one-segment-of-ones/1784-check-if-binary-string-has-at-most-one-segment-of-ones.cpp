class Solution {
public:
    bool checkOnesSegment(string s) {
        bool flag = false;
        int cnt=0;
        for(char c:s){
            if(c=='1')
                cnt++;
        }
        int len=0;
        for(char c:s){
            if(c=='1')len++;
            else{
                if(cnt==len)
                    return true;
                len=0;
            }
        }
        return cnt==len;
    }
};