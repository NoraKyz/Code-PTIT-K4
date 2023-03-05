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

ll Solve(string s) 
{
    stack<char> st;
    for(auto it : s) 
    {
        if(it == '+' || it == '-' || it == '*' || it == '%' || it == '/' || it == '^')
        {
            ll x = st.top(); st.pop();
            ll y = st.top(); st.pop();

            ll tmp = 0;
            if(it == '+') tmp = y+x;
            else if(it == '-') tmp = y-x;
            else if(it == '*') tmp = y*x;
            else if(it == '/') tmp = y/x;
            else if(it == '%') tmp = y%x;
            else 
            {
                tmp = 1;
                FOR(i,1,x,1) tmp *= y;
            }

            st.push(tmp);
        }
        else st.push((ll)(it-'0'));
    }

    return st.top();
}
    
int main()
{   
    fast_cin
    cin >> t;
    while(t--)
    {
        cin >> s;
        cout << Solve(s) << '\n';
    }
    
    return 0;
}