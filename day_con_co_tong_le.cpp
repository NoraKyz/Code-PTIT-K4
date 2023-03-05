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
ll a[101], x[101];
vector<vector<ll>> res;

void Solve(ll i, ll st, ll k, ll currentSum) 
{
    FOR(j,st,n,1) 
    {
        x[i] = a[j];
        ll tmp = currentSum + a[j];

        if(i < k) Solve(i+1,j+1,k,tmp);
        else if(tmp % 2) 
        {
            vector<ll> ans;
            FOR(h,1,k,1) ans.pb(x[h]);
            res.pb(ans);
        }
    }
}
    
int main()
{   
    fast_cin
    cin >> t;
    while(t--)
    {
        res.clear();

        cin >> n;
        FOR(i,1,n,1) cin >> a[i];
        sort(a+1,a+1+n,greater<ll>());

        FOR(i,1,n,1) Solve(1,1,i,0);

        sort(all(res));
        for(auto it : res) 
        {
            for(auto it2 : it) cout << it2 << " ";
            cout << '\n';
        }
    }
    
    return 0;
}