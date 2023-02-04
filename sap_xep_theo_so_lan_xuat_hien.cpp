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

ll t, n, x;
pair<ll,ll> a[100001];

bool ss(pair<ll,ll> a, pair<ll,ll> b)
{
    if(a.se != b.se) return a.se > b.se;
    else return a.first < b.first;
}
    
int main()
{   
    fast_cin
    cin >> t;
    while(t--)
    {
        unordered_map<ll,ll> m;
        cin >> n;
        FOR(i,1,n,1) 
        {
            cin >> a[i].first;
            m[a[i].first]++;
        }
        FOR(i,1,n,1) 
        {
            a[i].second = m[a[i].first];
        }

        sort(a+1,a+1+n,ss);

        FOR(i,1,n,1) cout << a[i].first << " ";
        cout << '\n';

    }
    
    return 0;
}