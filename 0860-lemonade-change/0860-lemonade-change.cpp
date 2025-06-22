class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int,int>m;
        m[5]=0;
        m[10]=0;
        m[20]=0;
        for(int i:bills){
            int x=i-5;
            while(x>=20 && m[20]>0){
                x-=20;
                m[20]--;
            }
            while(x>=10 && m[10]>0){
                x-=10;
                m[10]--;
            }
            while(x>=5 && m[5]>0){
                x-=5;
                m[5]--;
            }
            m[i]++;
            if(x!=0)return false;
        }
        return true;
    }
};