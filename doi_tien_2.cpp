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

ll t, n, s, res = 1e9, sum = 0;
ll a[101];

void Solve(ll i, ll currentSum, ll lastSum, ll currentRes)
{
    FOR(j,0,1,1) 
    {
        ll tmp = currentSum + a[i]*j;
        if(tmp == s) 
        {
            res = min(res, currentRes + j);
        }
        else if(tmp < s) 
        {
            if(tmp + (lastSum - a[i]) >= s && currentRes < res) Solve(i+1,tmp,lastSum-a[i],currentRes+j);
        }
    }
}
    
int main()
{   
    fast_cin
    cin >> n >> s;
    FOR(i,1,n,1) 
    {
        cin >> a[i];
        sum += a[i];
    }

    Solve(1,0,sum,0);

    if(res != 1e9) cout << res;
    else cout << -1;
    
    return 0;
}