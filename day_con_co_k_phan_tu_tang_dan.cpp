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
ll a[101], x[101];

void Solve(ll i, ll st)
{
    FOR(j,st,n,1) 
    {
        x[i] = j;
        if(i < k)
        {
            if(i+n-j+1 >= k) Solve(i+1,j+1);
        }
        else 
        {
            FOR(h,1,k,1) cout << a[x[h]] << " ";
            cout << '\n';
        }
    }
}
    
int main()
{   
    fast_cin
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        FOR(i,1,n,1) cin >> a[i];
        sort(a+1,a+1+n);

        Solve(1,1);
    }
    
    return 0;
}