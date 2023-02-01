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
ll x[10];

bool Check()
{   
    ll day = x[1]*10 + x[2];
    ll month = x[3]*10 + x[4];
    ll year = x[5]*1000 + x[6]*100 + x[7]*10 + x[8];

    if(day != 0 && month != 20 && month != 0 && month != 22 && year >= 2000) return 1;
    return 0;
}

void Display()
{
    cout << x[1] << x[2] << '/';
    cout << x[3] << x[4] << '/';
    cout << x[5] << x[6] << x[7] << x[8] << '\n';
}

void Solve(ll i)
{
    FOR(j,0,1,1)
    {
        if(j == 0) 
        {
            x[i] = 0;
            if(i < 8)
            {
                Solve(i+1);
            }
            else 
            {
                if(Check()) Display();
            }
        }
        else 
        {
            x[i] = 2;
            if(i < 8)
            {
                Solve(i+1);
            }
            else 
            {
                if(Check()) Display();
            }
        }
    }
}
    
int main()
{   
    fast_cin
    Solve(1);
    
    return 0;
}