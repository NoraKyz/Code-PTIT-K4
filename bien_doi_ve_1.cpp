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
ll res;

void Solve(ll i, ll currentN) 
{
    FOR(j,0,1,1) 
    {
        if(j == 0) 
        {
            if(currentN % 2 == 0) 
            {
                ll tmp = currentN/2;
                if(tmp == 1) res = min(res,i);
                else if(i < res) Solve(i+1,tmp);
            }
            else 
            {
                ll tmp = currentN-1;
                if(tmp == 1) res = min(res,i);
                else if(i < res) Solve(i+1,tmp);
            }
        }
        else 
        {
            if(currentN % 3 == 0) 
            {
                ll tmp = currentN/3;
                if(tmp == 1) res = min(res,i);
                else if(i < res) Solve(i+1,tmp);
            }
            else 
            {
                ll tmp = currentN-1;
                if(tmp == 1) res = min(res,i);
                else if(i < res) Solve(i+1,tmp);
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
        cin >> n;
        res = INT_MAX;
        Solve(1,n);
        cout << res << '\n';
    }
    
    return 0;
}