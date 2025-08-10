class Solution {
    unordered_map<int, vector<unordered_map<char,int>>> m;
    
    void get_map(string x) {
        unordered_map<char,int> m1;
        for(char c : x) {
            m1[c]++;
        }
        m[x.length()].push_back(m1);
    }
    
    bool is_match(unordered_map<char,int>& m1, unordered_map<char,int>& m2) {
        if(m1.size() != m2.size()) return false;
        for(auto &[x,y] : m1) {
            if(m2.find(x) == m2.end() || m2[x] != y) return false;
        }
        return true;
    }
    
public:
    bool reorderedPowerOf2(int n) {
        long long x = 1;
        while(x <= 1e9) {
            get_map(to_string(x));
            x <<= 1;
        }

        string s = to_string(n);
        unordered_map<char,int> m1;
        for(char c : s) m1[c]++;
        
        if(m.find(s.length()) == m.end()) return false;
        
        for(auto &mp : m[s.length()]) {
            if(is_match(m1, mp)) return true;
        }
        return false;
    }
};
