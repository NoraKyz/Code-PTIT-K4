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
ll dp[105][905] = {0};
    
int main()
{   
    fast_cin

    FOR(i,0,9,1) dp[1][i] = 1;

    FOR(i,1,100,1) 
    {
        dp[i][1] = 1;
        FOR(j,2,900,1) 
        {
            FOR(k,j-9,j,1) if(k > 0) dp[i][j] = (dp[i][j] + dp[i-1][k])%MOD;
        }
    }

    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        if(k > 900) cout << 0;
        else cout << dp[n][k];

        cout << '\n';

        /*
            dp[i][j] so luong cac so co i chu so voi tong cac chu so bang j
            xet so co i chu so voi tong bang j se duoc duoc tao bang cach them chu so tu
            0 dem 9 vao cuoi cac so co i-1 chu so voi tong cac chu so tu j-9 -> j

            dp[i][0] = 0
            dp[i][1] = 1

            dp[1][2] = 2
            dp[2][2] = 20 11 = dp[1][1] + dp[1][2]
            dp[3][2] = 200 101 110 = dp[2][1] + dp[2][2] 10 11 20
            dp[4][2] = 2000 1010 1100 1001

            dp[1][3] = 3
            dp[2][3] = 12 21 30
            dp[3][3] = 102 201 120 210 300 111
            dp[4][3] = 3000 2001 2010 2100 1002 1020 1200 1110 1011 1101
        */ 


    }
    
    return 0;
}