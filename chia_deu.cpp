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
ll a[101], f[101] = {0}, x[101] = {0};

// 1 2 3
// 1 0 1

void Progress()
{
    ll l = 1, sumTarget;

    while(x[l] == 0) l++;
    sumTarget = f[l] - f[0]; 

    FOR(i,l+1,n,1) 
    {
        //cout << x[i] << " ";
        if(x[i] == 1) 
        {
            if(sumTarget != f[i] - f[l]) return;
            l = i;
        }
    }
    //cout << '\n';
    res++;
}

void Solve(ll i, ll numOf1)
{
    FOR(j,0,1,1) 
    {
        x[i] = j;
        ll tmp = numOf1 + j;
        if(i < n) 
        {
            if(tmp <= k) Solve(i+1,tmp);
        }
        else if(tmp == k && x[n]) Progress();
    }
}
    
int main()
{   
    fast_cin
    cin >> n >> k;
    FOR(i,1,n,1) 
    {
        cin >> a[i];
        f[i] = f[i-1] + a[i];
    }

    Solve(1,0);

    cout << res;
    
    return 0;
}