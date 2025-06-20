class Solution {
public:
    int maxDistance(string s, int k) {
        int n = s.length();
        int e = 0, w = 0, cn = 0, cs = 0;
        int ans = 0;
        int x = 0, y = 0, z1 = 0, z2 = 0, z3 = 0, z4 = 0,i=0;

        for (char ch : s) {
            if (ch == 'E')
                e++;
            else if (ch == 'W')
                w++;
            else if (ch == 'N')
                cn++;
            else if (ch == 'S')
                cs++;
            x = (e + cn) - (w + cs);
            y = w + cs;
            z1 = x + 2 * min(k, y);
            x = (w + cn) - (e + cs);
            y = e + cs;
            z2 = x + 2 * min(k, y);
            x = (e + cs) - (w + cn);
            y = w + n;
            z3 = x + 2 * min(k, y);
            x = (w + cs) - (e + cn);
            y = e + n;
            z4 = x + 2 * min(k, y);

            int a = max(z1, max(z2, max(z3, z4)));
            a = max(a, 0);
            a = min(a, i + 1);
            ans = max(ans, a);
            i++;
        }

        return ans;
    }
};