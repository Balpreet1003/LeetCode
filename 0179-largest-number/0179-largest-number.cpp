class Solution {
private:
    static bool cmd(string&a,string&b){
        string t1=a+b;
        string t2=b+a;
        return t1>t2;
    }
public:
    string largestNumber(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);

        vector<string>snums;
        for(auto i:nums){
            snums.push_back(to_string(i));
        }

        sort(snums.begin(),snums.end(),cmd);
        if(snums[0]=="0")
            return "0";
        string ans="";
        for(auto i:snums){
            ans+=i;
        }
        return ans;
    }
};