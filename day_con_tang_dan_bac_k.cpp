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

ll t, n, k, res = 0;
ll a[1001];

void Solve(ll i, ll cnt) 
{
    if(cnt == k) res++;
    else 
    {
        FOR(j,i+1,n,1) 
        {
            if(a[i] < a[j]) Solve(j,cnt+1);
        } 
    }
}
    
int main()
{   
    fast_cin

    cin >> n >> k;
    FOR(i,1,n,1) cin >> a[i];
    
    FOR(i,1,n,1) Solve(i,1);
    cout << res;
    
    return 0;
}