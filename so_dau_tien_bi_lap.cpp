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
ll a[1000001];
    
int main()
{   
    fast_cin
    cin >> t;
    while(t--)
    {
        cin >> n;
        ll res, kt = 0;
        unordered_map<ll,ll> m;
        FOR(i,1,n,1) 
        {
            cin >> a[i];
            m[a[i]]++;
        }

        FOR(i,1,n,1) 
        {
            if(m[a[i]] > 1) 
            {
                res = a[i];
                kt = 1;
                break;
            }
        }

        if(kt == 0) cout << "NO";
        else cout << res;
        cout << '\n';
    }
    
    return 0;
}