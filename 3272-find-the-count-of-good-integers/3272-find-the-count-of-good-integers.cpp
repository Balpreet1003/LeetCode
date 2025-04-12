#define ll long long
#define vi vector<ll>

class Solution {
    vi a;
    ll ans = 0;
    unordered_set<ll> trace;

    void getFactorial() {
        a = vi(11, 1);
        for (int i = 2; i < 11; i++) {
            a[i] = i * a[i - 1];
        }
    }

    ll cntPremu(vector<ll>& b, int n) {
        ll cnt = a[n];
        for (int i = 0; i < 10; i++) {
            cnt /= a[b[i]];
        }
        return cnt;
    }

    ll getCount(string s, int n) {
        string t = s;
        sort(t.begin(), t.end());
        if (trace.count(stoll(t)))
            return 0;
        trace.insert(stoll(t));

        vi b(10, 0);
        for (auto c : s) {
            b[c - '0']++;
        }

        ll total_permu = cntPremu(b, n);
        ll invalid_permu = 0;
        if(b[0]>0){
            b[0]--;
            invalid_permu=cntPremu(b,n-1);
        }
        return total_permu - invalid_permu;
    }

    void generatePalindromes(int& n, int& k, int i, string& s) {
        if (i >= (n + 1) / 2) {
            if (stoll(s) % (ll)k == 0)
                ans += getCount(s, n);
            return;
        }

        char ch = (i == 0) ? '1' : '0';
        for (; ch <= '9'; ch++) {
            s[i] = ch;
            s[n - i - 1] = ch;
            generatePalindromes(n, k, i + 1, s);
        }
    }

public:
    long long countGoodIntegers(int n, int k) {
        getFactorial();
        string s(n, ' ');
        generatePalindromes(n, k, 0, s);
        return ans;
    }
};