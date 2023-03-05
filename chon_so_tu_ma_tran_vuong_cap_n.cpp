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

ll n, k, res = 0;
ll a[105][105], x[100];

ll Check() 
{
    ll tmp = 0;
    FOR(i,1,n,1) tmp += a[i][x[i]];
    if(tmp != k) return 0;
    
    return 1;
}
    
int main()
{   
    fast_cin
    cin >> n >> k;
    FOR(i,1,n,1) 
    {
        FOR(j,1,n,1) cin >> a[i][j];
    }

    FOR(i,1,n,1) x[i] = i;

    do 
    {
        res += Check();
    } while(next_permutation(x+1,x+1+n));
    cout << res << '\n';

    do 
    {
        if(Check()) 
        {
            FOR(i,1,n,1) cout << x[i] << " ";
            cout << '\n';
        }
    } while(next_permutation(x+1,x+1+n));
    
    return 0;
}