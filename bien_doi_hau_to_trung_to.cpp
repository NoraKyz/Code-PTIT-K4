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

string Solve() 
{
    stack<string> st;
    ll n = s.size() - 1;

    FOR(i,0,n,1)
    {
        if(s[i] >= 'A' && s[i] <= 'Z') 
        {           
            st.push(string(1,s[i]));
        }
        else 
        {
            string tmp = "(";
            string x = st.top(); st.pop();
            string y = st.top(); st.pop();
            tmp += y + s[i] + x + ')';
            st.push(tmp);
        }
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
        cout << Solve() << '\n';
    }
    
    return 0;
}