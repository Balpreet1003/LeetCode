#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <limits>
#include <unordered_map>
#include <unordered_set>
#include <climits>

#define ll long long
#define ld long double
#define vi vector
using namespace std;

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

vi<ll> dx={-1,0,1,0};
vi<ll> dy={0,1,0,-1};

ll longestValidParentheses(string s)
{
    stack<ll> st;
    st.push(-1);

    ll result=0;

    for (ll i=0; i<s.length(); i++)
    {
        if(s[i]=='(')
            st.push(i);
        else 
        {
            st.pop();

            if(st.empty())
                st.push(i);
            else
                result=max(result, i-st.top());
        }
    }
    return result;
}

void solve() 
{
    string s;
    cin>>s;
    cout<<longestValidParentheses(s)<<endl;
}

int main() 
{
    ll t=1;
    while (t--)
    {
        solve();
    }
    return 0;
}