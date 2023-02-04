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
ll f[1001][1001] = {0};
    
int main()
{   
    fast_cin
    cin >> t;
    while(t--)
    {
        cin >> s1 >> s2;

        ll n1 = s1.size(), n2 = s2.size();

        ll res = 0;

        FOR(i,1,n1,1)
        {           
            FOR(j,1,n2,1) 
            {
                f[i][j] = 0;
                if(s1[i-1] == s2[j-1]) 
                {
                    f[i][j] = f[i-1][j-1]+1;
                }
                else 
                {
                    f[i][j] = max(f[i-1][j], f[i][j-1]);
                }
            }
        }

        cout << f[n1][n2] << '\n';

    }
    
    return 0;
}