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
ll a[1000];

void Solve()
{
    ll i = k;

    while(i > 0) 
    {
        if(a[i] < n-k+i) break;
        i--;
    }

    if(i == 0) FOR(j,1,k,1) cout << j << " ";
    else 
    {
        a[i]++;
        FOR(j,i+1,k,1) a[j] = a[i] + j - i;

        FOR(j,1,k,1) cout << a[j] << " ";
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
        Solve();
        cout << '\n';
    }
    
    return 0;
}