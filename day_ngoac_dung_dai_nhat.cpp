#include<bits/stdc++.h>
#define FOR(i,a,b,k) for (ll i=a;i<=b;i+=k)
#define FORD(i,a,b,k) for (ll i=a;i>=b;i-=k)
#define pb(i) push_back(i)
#define ll long long int
#define all(a) (a).begin(), (a).end()
#define fi first
#define se second
#define fast_cin ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const ll MOD=1e9+7;

ll t, n;
string s;

ll Solve()
{
    ll res = 0;
    stack<ll> st;
    st.push(-1);
    ll n = s.size() - 1;
    FOR(i,0,n,1)
    {
        if(s[i] == '(') st.push(i);
        else 
        {
            st.pop();
            if(!st.empty()) res = max(res,i - st.top());
            else st.push(i);
        }
    }

    return res;
}
    
int main()
{   
    fast_cin
    cin >> t;
    while(t--)
    {
        cin >> s;
        cout << Solve() << '\n';
    }
    
    return 0;
}