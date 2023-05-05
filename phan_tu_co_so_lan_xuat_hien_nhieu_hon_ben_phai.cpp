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
ll x[1000001], a[1000001], res[1000001];

void Solve()
{
    memset(a,1,sizeof(a));

    FOR(i,1,n,1) 
    {
        a[x[i]]++;
        res[i] = -1;
    }

    stack<ll> st;
    ll i = 1;

    while(i <= n) 
    {
        while(!st.empty()) 
        {
            if(a[x[i]] <= a[x[st.top()]]) break;
            res[st.top()] = x[i];
            st.pop();
        }
        st.push(i);

        i++;
    }

    FOR(i,1,n,1) cout << res[i] << " ";
    cout << '\n';
}
    
int main()
{   
    fast_cin
    cin >> t;
    while(t--)
    {
        cin >> n;
        FOR(i,1,n,1) cin >> x[i];

        Solve();
    }
    
    return 0;
}