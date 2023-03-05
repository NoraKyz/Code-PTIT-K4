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
string s1, s2;
ll dp[101][101] = {0};
    
int main()
{   
    fast_cin
    cin >> t;
    while(t--)
    {
        cin >> s1 >> s2;
        ll n1 = s1.size(), n2 = s2.size();

        FOR(i,1,n1,1) dp[i][0] = i;
        FOR(i,1,n2,1) dp[0][i] = i;

        FOR(j,1,n2,1)
        {
            FORD(i,j-1,1,1) 
            {
                if(s1[i-1] == s2[j-1]) 
                {
                    dp[i][j] = dp[i-1][j-1];
                }
                else 
                {
                    dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
                }
            }
        }

        cout << dp[n1][n2] << '\n';
    }
        
    return 0;
}