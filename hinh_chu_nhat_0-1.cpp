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

ll t, n, m, x, res = 0;
ll a[550][550];
ll b[1000], c[1000];

/*
    xet tung hang lam day
*/

void Solve(ll j)
{
    memset(b,0,sizeof(b));
    memset(c,0,sizeof(c));

    stack<ll> st;
        
    FOR(i,1,m,1) 
    {
        while(!st.empty() && a[j][i] < a[j][st.top()]) 
        {
            b[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    FOR(i,1,m,1) if(b[i] == 0) b[i] = m+1;
    
    // clear stack
    while(!st.empty()) st.pop();

    FORD(i,m,1,1) 
    {
        while(!st.empty() && a[j][i] < a[j][st.top()]) 
        {
            c[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }

    FOR(i,1,m,1) res = max(res, a[j][i] * (b[i] - c[i] - 1));
}
    
int main()
{   
    fast_cin
    cin >> t;
    while(t--)
    {
        res = 0;
        memset(a,0,sizeof(a));
        cin >> n >> m;
        FOR(i,1,n,1) 
        {
            FOR(j,1,m,1) 
            {
                cin >> x;
                if(x) a[i][j] = a[i-1][j] + 1;
                else a[i][j] = 0;
            }
        }

        FOR(i,1,n,1) Solve(i);

        cout << res << '\n';

    }
    
    return 0;
}