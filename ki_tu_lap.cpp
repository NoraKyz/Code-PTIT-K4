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

ll t, n, res = 1e9;
string s[15];
ll a[15];
bool kt[15] = {0};

ll Count(ll i) 
{
    ll ans = 0;
    if(i == 1) return ans; 

    ll b[500] = {0};
    for(auto it : s[a[i]]) b[it]++;
    for(auto it : s[a[i-1]]) if(b[it] != 0) ans ++;
    return ans;
}

void Solve(ll i, ll sumLoop) 
{
    FOR(j,1,n,1) 
    {
        if(kt[j] == 0) 
        {
            a[i] = j;
            ll tmp = sumLoop + Count(i);
            if(i < n) 
            {
                if(tmp < res) 
                {
                    kt[j] = 1;
                    Solve(i+1,tmp);
                    kt[j] = 0;
                }
            } 
            else  res = min(res, tmp); 
                     
        }
    }
}
    
int main()
{   
    fast_cin
    
    
    {
        cin >> n;
        FOR(i,1,n,1) cin >> s[i];

        Solve(1,0);

        cout << res;
    }
    
    return 0;
}