#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minMaxDifference(int num) {
        string s=to_string(num);

        int mini=num,maxi=num;
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                string s1=s;
                if(i!=j){
                    for(int k=0;k<s.length();k++){
                        if(s1[k]-'0'==i){
                            s1[k]=j+'0';
                        }
                    }
                }
                maxi=max(maxi,stoi(s1));
                mini=min(mini,stoi(s1));
            }
        }
        return maxi-mini;
    }
};