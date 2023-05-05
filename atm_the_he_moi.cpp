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

ll t, n, c;
vector<ll> v;
unordered_map<ll, ll> m;
    
int main()
{   
    fast_cin

    cin >> t;
    while(t--)
    {
        v.clear();
        m.clear();

        cin >> n >> c;

        ll tmp = 1000;
        FOR(i,0,c,1) 
        {
            v.pb(1*tmp);
            v.pb(2*tmp);
            v.pb(3*tmp);
            v.pb(5*tmp);
            tmp*=10;
        }

        ll res = 0, cnt = 1;

        ll u = v.size() - 1;

        while(u >= 0) 
        {           
            ll dem = n / v[u];
            res += dem;
            m[v[u]] = dem;
            n -= dem * v[u];

            u--;
        }

        if(n > 0) 
        {
            cout << 0 << '\n';
            continue;
        }

        tmp = 1000;

        FOR(i,0,c,1) 
        {
            ll x = min(m[1*tmp], m[3*tmp]);

            ll y = min(m[1*tmp], m[5*tmp]);

            cnt *= 1 << (x + y);

            tmp*=10;
        }

        cout << res << " " << cnt << '\n';
    }
    
    return 0;
}