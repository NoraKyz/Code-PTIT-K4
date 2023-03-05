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
ll a[101];
string s[101];
    
int main()
{   
    fast_cin
    
    ll res = INT_MAX;

    cin >> n >> k;
    FOR(i,1,n,1) cin >> s[i];

    FOR(i,1,k,1) a[i] = i;

    do
    {
        vector<ll> ans;
        FOR(i,1,n,1) 
        {
            string tmp = "";
            FOR(j,1,k,1) tmp += s[i][a[j]-1];
            ans.pb(stoll(tmp));
        }
        
        auto M = max_element(all(ans));
        auto m = min_element(all(ans));

        //for(auto it : ans) cout << it << " ";

        res = min(res,*M - *m);
    }
    while(next_permutation(a+1,a+1+k));

    cout << res;

    
    return 0;
}