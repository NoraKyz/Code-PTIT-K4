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
ll a[100] = {0}, x[100];
vector<string> ans;

void Solve(ll i, ll st, ll m)
{
    FOR(j,st,n,1)
    {
        if(x[j] > m) 
        {
            a[i] = j;
            if(i >= 2) 
            {
                string res = "";
                FOR(h,1,i,1) res += to_string(x[a[h]]) + " ";
                ans.pb(res);
            }
            
            if(i < n) 
            {      
                Solve(i+1,a[i]+1,x[j]);
            }
        }
    }
}
    
int main()
{   
    fast_cin
    cin >> n;
    FOR(i,1,n,1) cin >> x[i];
    Solve(1,1,-1);
    sort(all(ans));

    for(auto it : ans) cout << it << '\n';
    
    return 0;
}