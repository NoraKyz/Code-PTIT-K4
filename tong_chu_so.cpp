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

ll t, n, m;
string dp[101][10005];

string Min(string a, string b)
{
    ll lena = a.size();
    ll lenb = b.size();
    
    if(lena > lenb) return b;
    else if(lena < lenb) return a;

    return a < b ? a : b;
}
    
int main()
{   
    fast_cin

    FOR(i,1,100,1)
    {
        FOR(j,1,10000,1) dp[i][j] = "";
    }

    FOR(i,1,9,1) dp[i][i*i] = to_string(i);

    FOR(i,1,100,1) 
    {
        FOR(j,1,10000,1) 
        {
            if(i/9*81 + (i%9)*(i%9) < j) break;

            if(dp[i][j] != "") continue;
            
            FOR(k,0,9,1) 
            {
                if(i <= k || j <= k*k) break;

                if(dp[i-k][j-k*k] == "") continue;

                if(dp[i][j] != "") dp[i][j] = Min(dp[i-k][j-k*k] + char(k+48), dp[i][j]);
                else dp[i][j] = dp[i-k][j-k*k] + char(k+48);
            }  
        }
    }

    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        if(dp[n][m] != "") cout << dp[n][m];
        else cout << -1;
        cout << '\n';
    }
    
    return 0;
}