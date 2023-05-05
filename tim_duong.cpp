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

ll t, n, m, s1, s2, t1, t2;
char a[505][505];
bool vs[505][505];
ll x[4]={0,0,1,-1};
ll y[4]={1,-1,0,0};

bool Solve(ll u, ll v, ll cnt, ll lastX, ll lastY) 
{
    FOR(i,0,3,1) 
    {
        ll c = u + x[i];
        ll d = v + y[i];

        if(c >= 1 && c <= n && d >= 1 && d <= m) 
        {
            if(!vs[c][d] && a[c][d] == '.')
            {
                ll tmpCnt = cnt;

                if(x[i] != lastX || y[i] != lastY) tmpCnt++; // doi huong

                if(tmpCnt == 3) return 0;

                if(c == t1 && d == t2) return 1;

                vs[c][d] = 1;
                if(Solve(c, d, tmpCnt, x[i], y[i])) 
                {
                    return 1;
                }
                vs[c][d] = 0;
            }
        }
    }

    return 0;
}
    
int main()
{   
    fast_cin
    cin >> t;
    while(t--)
    {
        memset(vs, 0, sizeof(vs));
        bool res = 0;

        cin >> n >> m;
        FOR(i,1,n,1) FOR(j,1,m,1) 
        {
            cin >> a[i][j];

            if(a[i][j] == 'S') s1 = i, s2 = j;

            if(a[i][j] == 'T') t1 = i, t2 = j;         
        }

        a[s1][s2] = a[t1][t2] = '.';

        FOR(i,0,3,1) 
        {
            memset(vs, 0, sizeof(vs));

            vs[s1][s2] = 1;

            if(Solve(s1, s2, 0, x[i], y[i])) 
            {
                res = 1;
                break;
            }
        }

        cout << (res ? "YES" : "NO") << '\n';
    }
    
    return 0;
}