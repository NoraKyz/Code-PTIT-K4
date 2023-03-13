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
ll a[100001], b[100001], c[100001];
    
int main()
{   
    fast_cin
    cin >> t;
    while(t--)
    {
        memset(b,0,sizeof(b));
        memset(c,0,sizeof(c));
        
        ll res = -1;
        cin >> n;
        FOR(i,1,n,1) cin >> a[i];

        stack<ll> st;
        
        FOR(i,1,n,1) 
        {
            while(!st.empty() && a[i] < a[st.top()]) 
            {
                b[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        FOR(i,1,n,1) if(b[i] == 0) b[i] = n+1;
        
        // clear stack
        while(!st.empty()) st.pop();

        FORD(i,n,1,1) 
        {
            while(!st.empty() && a[i] < a[st.top()]) 
            {
                c[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        FOR(i,1,n,1) res = max(res, a[i] * (b[i] - c[i] - 1));

        cout << res << '\n';
    }
    
    return 0;
}