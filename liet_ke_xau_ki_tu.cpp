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
ll a[100] = {0};
char c;

void Solve(ll i, ll st)
{
    FOR(j,st,c,1)
    {
        {
            a[i] = j;
            
            if(i < k) 
            {
                Solve(i+1,a[i]);
            }
            else 
            {
                FOR(h,1,k,1) cout << (char) a[h];
                cout << '\n';
            }
        }
    }
}
    
int main()
{   
    fast_cin
    
        cin >> c >> k;
        n = c-'A'+1;
        Solve(1,'A');
        cout << '\n';
    
    
    return 0;
}