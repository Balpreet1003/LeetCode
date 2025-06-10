class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char, int> m;
        for (char ch : s) m[ch]++;
        
        vector<int> a, b;
        for (auto &[ch, count] : m) {
            if (count % 2 == 0) b.push_back(count);
            else a.push_back(count);
        }
        
        if (a.empty() || b.empty()) return 0; 
        
        int x = *max_element(a.begin(), a.end());
        int y = *min_element(b.begin(), b.end());
        
        return x - y;
    }
};