class Solution {
public:
    int minAnagramLength(string input_str) {
        int n = input_str.size();
        vector<int> freq(26, 0);

        // Count frequency of each character
        for (char c : input_str) {
            freq[c - 'a']++;
        }

        // Try each divisor of n
        for (int k = 1; k <= n; k++) {
            if (n % k != 0) continue;  // k must divide n
            bool ok = true;

            // For each character frequency, it must be divisible by (n/k)
            int parts = n / k;
            for (int f : freq) {
                if (f % parts != 0) {
                    ok = false;
                    break;
                }
            }

            if (ok) return k;  // smallest valid k
        }

        return n; 
    }
};