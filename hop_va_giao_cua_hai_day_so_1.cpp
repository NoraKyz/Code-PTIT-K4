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

ll t, n, m;
ll a[100001], b[100001];
    
int main()
{   
    fast_cin
    cin >> t;
    while(t--)
    {
        set<ll> st;
        cin >> n >> m;
        FOR(i,1,n,1) 
        {
            cin >> a[i];
            st.insert(a[i]);
        }
        FOR(i,1,m,1) 
        {
            cin >> b[i];
            st.insert(b[i]);
        }

        for(auto it : st) cout << it << " ";
        cout << '\n';
        FOR(i,1,m,1) 
        {
            ll d = upper_bound(a+1,a+1+n,b[i]) - a;
            if(a[d-1] == b[i]) cout << b[i] << " ";
        }
        cout << '\n';
    }
    
    return 0;
}