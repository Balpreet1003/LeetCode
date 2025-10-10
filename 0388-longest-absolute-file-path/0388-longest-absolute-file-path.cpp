class Solution {
public:
    int lengthLongestPath(string input) {
        int maxlength = 0;
        stack<int> pathlengths;
        stringstream ss(input);
        string line;
        
        while (getline(ss, line)) {
            int depth = 0;

            while (line[depth] == '\t') {
                depth++;
            }

            while (pathlengths.size() > depth) {
                pathlengths.pop();
            }

            string name = line.substr(depth);
            int length = (pathlengths.empty() ? 0 : pathlengths.top()) + name.length() + (pathlengths.empty() ? 0 : 1);

            if (name.find('.') != string::npos) {
                maxlength = max(maxlength, length);
            } else {
                pathlengths.push(length);
            }
        }
        return maxlength;
    }
};