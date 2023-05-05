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

ll merge(ll a[], ll l, ll m, ll r)
{
    vector<ll> x(a+l,a+m+1);
    vector<ll> y(a+m+1,a+r+1);

    ll i = 0, j = 0;
    ll cnt = 0;

    while(i < x.size() && j < y.size())
    {
        if(x[i] <= y[j]) 
        {
            a[l++] = x[i++];
        }
        else 
        {
            cnt += x.size() - i;
            a[l++] = y[j++];
        }
    }

    while(i < x.size()) 
    {
        a[l++] = x[i++];
    }

    while(j < y.size())
    {
        a[l++] = y[j++]; 
    }

    return cnt;
}

ll mergeSort(ll a[], ll l, ll r)
{
    ll dem = 0;
    if(l < r) 
    {
        ll m = (l+r) / 2;
        dem+=mergeSort(a,l,m);
        dem+=mergeSort(a,m+1,r);
        dem+=merge(a,l,m,r);
    }
    return dem;
}
    
int main()
{   
    fast_cin
    cin >> t;
    while(t--)
    {
        cin >> n;
        ll a[n+5];
        FOR(i,1,n,1) cin >> a[i];

        cout << mergeSort(a,1,n) << '\n';
    }
    
    return 0;
}
