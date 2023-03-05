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
vector<ll> v;
ll a[100] = {0,1};

ll Nap(ll n)
{
    ll res = 0;
    FOR(i,1,n,1) res = res*10 + a[i];
    return res; 
}

void Solve(ll i) 
{
    FOR(j,0,1,1) 
    {
        a[i] = a[j];
        if(i < 20) 
        {
            v.pb(Nap(i));
            Solve(i+1);
        }
    }
}

    
int main()
{   
    fast_cin
    v.pb(1);
    Solve(2);
    sort(all(v));
    cin >> t;
    while(t--)
    {
        cin >> n;
        ll d = upper_bound(all(v),n) - v.begin();

        cout << d  << '\n';
    }
    
    return 0;
}