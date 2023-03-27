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
pair<ll,ll> a[100001];
    
int main()
{   
    fast_cin
    cin >> t;
    while(t--)
    {
        ll res = 1;
        cin >> n;
        FOR(i,1,n,1) 
        {
            cin >> a[i].second >> a[i].first;
        }
        sort(a+1,a+1+n);

        ll currentEnd = a[1].first;
        FOR(i,2,n,1) 
        {
            if(a[i].second > currentEnd) 
            {
                currentEnd = a[i].first;
                res++;
            }
        }

        cout << res << '\n';
    }
    
    return 0;
}