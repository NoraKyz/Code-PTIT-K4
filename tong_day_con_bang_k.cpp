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

ll n, k, t, c;
ll x[100], a[100];

void Solve(ll i)
{
    FORD(j,1,0,1)
    {
        x[i] = j;
        if(i < n) Solve(i+1);
        else 
        {
            ll sum = 0;
            FOR(h,1,n,1) sum += x[h]*a[h];

            if(sum == k) 
            {
                bool kt = 0;
                c++;
                cout << "[";
                FOR(h,1,n,1) 
                {    
                    if(x[h] == 1) 
                    {
                        if(kt) cout << " ";
                        cout << a[h];
                        kt = 1;
                    }
                }
                cout << "] ";
            }         
        } 
    }
}
    
int main()
{   
    fast_cin
    cin >> t;
    while(t--)
    {
        c = 0;
        cin >> n >> k;
        FOR(i,1,n,1) cin >> a[i];
        sort(a+1,a+1+n);

        Solve(1);
        if(c == 0) cout << -1;
        cout << '\n';
    }
    
    return 0;
}