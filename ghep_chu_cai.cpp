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
ll a[100], kt[100] = {0};
char c;

bool Check()
{
    FOR(i,2,n-1,1) if(a[i] == 'A' || a[i] == 'E') 
    {
        if(a[i-1] != 'A' && a[i-1] != 'E' && a[i+1] != 'A' && a[i+1] != 'E') return 0;
    } 
    return 1;
}

void Solve(ll i)
{
    FOR(j,'A',c,1) 
    {
        if(kt[j] == 0)
        {
            a[i] = j;
            if(i < n) 
            {
                kt[j] = 1;
                Solve(i+1);
                kt[j] = 0;
            }
            else 
            {
                if(Check()) 
                {
                    FOR(h,1,n,1) cout << (char)a[h];
                    cout << '\n';
                }

            }
        }
    }
}
    
int main()
{   
    fast_cin
    
        cin >> c;
        n = c - 'A' + 1;
        Solve(1);
    
    
    return 0;
}