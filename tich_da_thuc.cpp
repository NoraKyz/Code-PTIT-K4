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
ll a[101], b[101];

void Solve()
{
    ll c[300] = {0};

    FOR(i,0,n-1,1) 
    {
        FOR(j,0,m-1,1) 
        {
            c[i+j] += a[i]*b[j];
        }
    }

    FOR(i,0,m+n-2,1) cout << c[i] << " ";
    cout << '\n';
}
    
int main()
{   
    fast_cin
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        FOR(i,0,n-1,1) cin >> a[i];
        FOR(i,0,m-1,1) cin >> b[i];

        Solve();
    }
    
    return 0;
}