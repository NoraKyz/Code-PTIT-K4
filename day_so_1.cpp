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
ll a[1000];
    
int main()
{   
    fast_cin
    cin >> t;
    while(t--)
    {
        cin >> n;
        FOR(i,1,n,1) cin >> a[i];

        bool kt = 0;
        cout << '[';
        FOR(i,1,n,1) 
        {
            if(kt) cout << " ";
            kt = 1;
            cout << a[i];
        }
        cout << ']' << '\n';

        FORD(i,n-1,1,1)
        {
            cout << '[';
            kt = 0;
            FOR(j,1,i,1) 
            {
                a[j] = a[j]+a[j+1];
                if(kt) cout << " ";
                kt = 1;
                cout << a[j];
            }
            cout << ']' << '\n';
        }
    }
    
    return 0;
}