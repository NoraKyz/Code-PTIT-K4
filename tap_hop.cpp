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

ll t, n, k, res, s;
ll a[1000] = {0};
bool kt[1000] = {0};

void Solve(ll i, ll st, ll sum)
{
    FOR(j,st,n,1)
    {
        if(kt[j] == 0) 
        {
            a[i] = j;
            
            if(i < k) 
            {
                if(sum+2*a[i]+1 <= s) 
                {
                    kt[j] = 1;
                    Solve(i+1,a[i]+1,sum+a[i]);
                    kt[j] = 0;
                }
            }
            else 
            {  
                if(sum+a[i] == s) res++;
            }
        }
    }
}
    
int main()
{   
    fast_cin

    while(1)
    {
        cin >> n >> k >> s;
        if(n == k && k == s && n == 0) return 0;
        res = 0;
        Solve(1,1,0);
        cout << res << '\n';
    }
    
    return 0;
}