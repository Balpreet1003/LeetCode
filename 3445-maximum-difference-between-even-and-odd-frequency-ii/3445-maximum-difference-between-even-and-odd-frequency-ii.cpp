class Solution {
    void precomputePrefixSum(vector<int>& prefixSumA, vector<int>& prefixSumB,
                             const string& s, const int& n, const int& a,
                             const int& b) {
        prefixSumA[0] = prefixSumB[0] = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] - '0' == a)
                prefixSumA[i + 1] = 1 + prefixSumA[i];
            else
                prefixSumA[i + 1] = prefixSumA[i];

            if (s[i] - '0' == b)
                prefixSumB[i + 1] = 1 + prefixSumB[i];
            else
                prefixSumB[i + 1] = prefixSumB[i];
        }
    }

    int calculateDifference(const string& s, const int& k, const int& a,
                            const int& b) {
        int n = s.size();
        vector<int> prefixSumA(n + 1), prefixSumB(n + 1);
        precomputePrefixSum(prefixSumA, prefixSumB, s, n, a, b);

        vector<int> minVal(4, INT_MAX); // What is the minDiff per case seen
        vector<int> minIdx(4, -1);      // At what idx did this case occur
        minVal[0] = minIdx[0] =
            0; // We start with 0, if we don't include anything

        // Now iterate for all valid window endpoints of size K
        int maxDiff = INT_MIN;
        for (int end = k; end <= n; ++end) {
            int parityA = prefixSumA[end] & 1;
            int parityB = prefixSumB[end] & 1;
            int parity = ((parityA ^ 1) << 1) + parityB;

            if (minVal[parity] != INT_MAX) {
                // B must have frequency > 0 in the subarray
                if (prefixSumB[minIdx[parity]] != prefixSumB[end]) {
                    maxDiff = max(maxDiff, (prefixSumA[end] - prefixSumB[end]) -
                                               minVal[parity]);
                }
            }

            // Slide window to right
            int start = end - k + 1;
            parityA = prefixSumA[start] & 1;
            parityB = prefixSumB[start] & 1;
            parity = (parityA << 1) + parityB;
            int startDiff = prefixSumA[start] - prefixSumB[start];

            if (startDiff < minVal[parity]) {
                minVal[parity] = startDiff;
                minIdx[parity] = start;
            }
        }
        return maxDiff;
    }

public:
    int maxDifference(string s, int k) {
        int n = s.size();
        int maxDiff = INT_MIN;
        for (int a = 0; a <= 4; ++a) {
            for (int b = 0; b <= 4; ++b) {
                if (a == b)
                    continue;
                int diff = calculateDifference(s, k, a, b);
                maxDiff = max(maxDiff, diff);
            }
        }
        return maxDiff;
    }
};