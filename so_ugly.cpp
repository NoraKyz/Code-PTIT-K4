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
ll a[4] = {0,2,3,5};
vector<ll> res = {1};
ll x = 1000000000000000000;

void Solve(ll currentPi, ll number, ll st)
{
    if(number > 60) return;
    FOR(i,st,3,1) 
    {
        ll tmp = currentPi;
        if(a[i] <= x / tmp) 
        {
            tmp *= a[i];
            res.push_back(tmp);
            Solve(tmp,number+1,i);
        }
        else break;
    }
}

int main()
{   
    fast_cin

    Solve(1,1,1);
    sort(all(res));
    //FOR(i,1,100,1) cout << res[i-1] << " ";

    cin >> t;
    while(t--) 
    {
        cin >> n;
        cout << res[n-1] << '\n';
    }
    
    
    return 0;
}