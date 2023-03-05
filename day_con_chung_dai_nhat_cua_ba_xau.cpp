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

ll t, n, m, l;
string s1, s2, s3;
ll dp[101][101][101] = {0};
    
int main()
{   
    fast_cin
    cin >> t;
    while(t--)
    {
        cin >> n >> m >> l;
        cin >> s1 >> s2 >> s3;

        FOR(i,1,n,1) 
        {
            FOR(j,1,m,1) 
            {
                FOR(k,1,l,1) 
                {
                    if(s1[i-1] == s2[j-1] && s2[j-1] == s3[k-1]) 
                    {
                        dp[i][j][k] = dp[i-1][j-1][k-1] + 1;
                    }
                    else 
                    {
                        ll x1 = max(max(dp[i-1][j][k],dp[i][j-1][k]),dp[i][j][k-1]);
                        ll x2 = max(max(dp[i-1][j-1][k],dp[i][j-1][k-1]),dp[i-1][j][k-1]);
                        dp[i][j][k] = max(x1,x2);
                    }
                }
            }
        }

        cout << dp[n][m][l] << '\n';
    }
    
    return 0;
}