class Solution {
public:
    // void removeOccurance(string& s,string& part){
    //     //1 case me solve karunga
    //     int start=s.find(part);
    //     if(start!=string::npos){
    //         // string left_part=s.substr(0,start);
    //         // int rSize=s.length()-(start+part.length());
    //         // string right_part=s.substr(start+part.length(),rSize);
    //         // s=left_part+right_part;
    //         s.erase(start,part.size());

    //         //baki re pe
    //         removeOccurance(s,part);
    //     }
    //     //base case
    //     else{
    //         return;
    //     }
    // }

    string removeOccurrences(string s, string part) {
        // int start
        // removeOccurance(s,part);
        // return s;

        //sol-2
        int pos=s.find(part);
        while(pos!=string::npos){
            s.erase(pos,part.size());
            pos=s.find(part);
        }
        return s;
    }
};