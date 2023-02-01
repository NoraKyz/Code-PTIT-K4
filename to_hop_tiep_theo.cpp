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

ll t, n, k;
ll a[100];

ll Solve()
{
    ll i = k;

    while(i > 0) 
    {
        if(a[i] < n-k+i) break;
        i--;
    }

    if(i == 0) return k;
    else
    {
        ll c = 0, kt[100] = {0};
        FOR(j,i,k,1) kt[a[j]] = 1;

        FOR(j,i,k,1) if(kt[a[i] + j - i + 1] == 0) c++;

        return c;
    }
}
    
int main()
{   
    fast_cin
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        FOR(i,1,k,1) cin >> a[i];
        cout << Solve() << '\n';
    }
    
    return 0;
}