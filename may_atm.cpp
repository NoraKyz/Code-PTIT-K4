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

ll t, n, s, res;
ll a[101];

void Solve(ll i, ll currentSum, ll currentNum) 
{
    FOR(j,0,1,1) 
    {
        ll tmp1 = currentSum + a[i]*j;
        ll tmp2 = currentNum + j;

        if(i < n) 
        {
            if(tmp1 < s && currentNum < res) Solve(i+1,tmp1,tmp2);
            else if(tmp1 == s) res = min(res,tmp2);
        } 
        else 
        {
            if(tmp1 == s) res = min(res,tmp2);
        }
    }
}
    
int main()
{   
    fast_cin
    cin >> t;
    while(t--)
    {
        ll sum = 0;
        res = 100;
        cin >> n >> s;
        FOR(i,1,n,1) 
        {
            cin >> a[i];
            sum += a[i];
        }

        if(sum > s) Solve(1,0,0);
        if(sum == s) res = n;

        if(res == 100) res = -1;
        cout << res << '\n';
    }
    
    return 0;
}