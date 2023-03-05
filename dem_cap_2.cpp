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
ll a[100001], b[100001];
    
int main()
{   
    fast_cin
    cin >> t;
    while(t--)
    {
        ll res = 0, x[100] = {0};

        cin >> n >> m;
        FOR(i,1,n,1) cin >> a[i];
        FOR(i,1,m,1) 
        {
            cin >> b[i];
            if(b[i] <= 2) x[b[i]]++;
        }

        sort(a+1,a+1+n);
        sort(b+1,b+1+m);

        /*
            x^y > y^x
            
            0 => khong ton tai
            1 => 0
            2 => 5... + 0,1
            3 => cac so lon hon no + 0,1,2
            > 4 => cac so lon hon no... + 0,1
        */

        FOR(i,1,n,1) 
        {
            if(a[i] == 0) continue;
            
            if(a[i] == 1) 
            {
                res += x[0];
                continue;
            }
            
            if(a[i] == 2) 
            {
                ll d = lower_bound(b+1,b+1+m,5) - b;
                res += m-d+1;
            }
            else  
            {
                ll d = upper_bound(b+1,b+1+m,a[i]) - b;
                res += m-d+1;
            }

            res+=x[0];
            res+=x[1];
            if(a[i] == 3) res+= x[2];

        }

        cout << res << '\n';
    }
    
    return 0;
}