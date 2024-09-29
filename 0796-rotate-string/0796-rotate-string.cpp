class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length()!=goal.length())return 0;
        string s1=s+s;
        return s1.find(goal)!=string::npos;
    }
};