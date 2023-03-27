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

ll t, n, x;
    
int main()
{   
    fast_cin
    cin >> t;
    while(t--)
    {
        ll a[20] = {0};
        ll sum = 0;

        cin >> n;
        FOR(i,1,n,1) 
        {
            cin >> x;
            a[x] ++;
            sum += x;
        }

        ll tmp = sum%3;

        if(tmp != 0) 
        {
            FOR(i,1,9,1) 
            {
                if(i%3 == tmp && a[i] > 0) 
                {
                    sum -= i;
                    a[i]--;
                    break;
                }
            }
        }

        if(sum%3 != 0) cout << -1;
        else 
        {
            FORD(i,9,0,1) 
            {
               while(a[i]--) cout << i; 
            }
        }

        cout << '\n';
    }
    
    return 0;
}