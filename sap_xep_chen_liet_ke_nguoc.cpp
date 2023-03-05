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

void Solve(ll i, ll a[])
{
    ll tmp = a[i], id = i;
    FOR(j,1,i-1,1) if(a[j] > a[id]) 
    {
        id = j;
        break;
    }
    FORD(j,i,id,1) a[j] = a[j-1];
    a[id] = tmp;

    ll b[1001];
    FOR(j,1,n,1) b[j] = a[j];

    if(i < n) Solve(i+1,b);   
    

    cout << "Buoc " << i-1 << ": ";
    FOR(j,1,i,1) cout << a[j] << " ";
    cout << '\n';
}
    
int main()
{   
    fast_cin

    ll a[1001];
    cin >> n;
    FOR(i,1,n,1) cin >> a[i];
    Solve(1,a);

    return 0;
}