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
vector<ll> a;

bool Solve(vector<ll> A, int K) {
    int N = a.size();
    int sum = accumulate(all(a), 0);
    if (sum % K != 0) {
        return false;
    }

    int target = sum / K;
    vector<vector<bool>> dp(N+1, vector<bool>(target+1, false));
    dp[0][0] = true;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= target; j++) {
            dp[i][j] = dp[i-1][j];
            if (j >= A[i-1]) {
                dp[i][j] = dp[i-1][j-A[i-1]];
            }
        }
    }
    return dp[N][target];
}
    
int main()
{   
    fast_cin
    cin >> t;
    while(t--)
    {
        a.clear();
        cin >> n >> k;
        FOR(i,1,n,1) 
        {
            ll x;
            cin >> x;
            a.pb(x);
        }
        cout << Solve(a,k) << '\n';
    }
    
    return 0;
}