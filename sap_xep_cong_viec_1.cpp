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
pair<ll,ll> a[10000];
    
int main()
{   
    fast_cin
    cin >> t;
    while(t--)
    {
        cin >> n;
        FOR(i,1,n,1) cin >> a[i].second;
        FOR(i,1,n,1) cin >> a[i].first;
        sort(a+1,a+1+n);

        ll res = 1, timeEnd = a[1].first;
        FOR(i,2,n,1) 
        {
            if(a[i].second >= timeEnd) 
            {
                res++;
                timeEnd = a[i].first;
            }
        }

        cout << res << '\n';
    }
    
    return 0;
}