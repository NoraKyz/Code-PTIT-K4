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

ll t, n, res = 1e9, m;
ll a[25][25], x[25], kt[25];

void Solve(ll i, ll currentSum, ll lastPoint) 
{
    FOR(j,2,n,1) 
    {    
        if(kt[j] == 0)
        {
            ll tmp = currentSum;
            tmp += a[lastPoint][j];

            if(i < n) 
            {
                if(tmp + (n-i)*m < res) 
                {
                    kt[j] = 1;
                    Solve(i+1,tmp,j);
                    kt[j] = 0;
                }
            } 
            else res = min(res,tmp + a[j][1]);
        }
    }
}
int main()
{   
    fast_cin

    cin >> n;
    FOR(i,1,n,1) FOR(j,1,n,1) 
    {
        cin >> a[i][j];
        m = min(m,a[i][j]);
    }

    Solve(2,0,1);

    cout << res;
   
    return 0;
}