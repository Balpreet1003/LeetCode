class Solution {
public:
    int maxDepth(string s) {
        if(s=="") return 0;
        int maxDepth=0;
        int cntOpen=0;
        for( int i=0;i<s.size();i++){

            if(s[i]=='('){
                cntOpen++;
                maxDepth=max(maxDepth,cntOpen);
            }
            // yaha pr hame closing milne pr check nhi krna pada ki
            // open >=1 hai yaa nhi because the question has given that
            //strings are VPS so it is must there is a closing bracket for 
            // each open bracket and in order
            else if(s[i]==')'){
             cntOpen--;
            }
            else{
               continue;
            }
        }
        return maxDepth; 
    }
};