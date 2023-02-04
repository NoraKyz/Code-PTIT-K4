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
 
//inline ll readll()       {char c;while(c=getchar(),c!='-'&&(c<'0'||c>'9'));bool sign=(c=='-');if(sign)c=getchar();ll  n=c-'0';while(c=getchar(),c>='0'&&c<='9')n=10*n+c-'0';return(!sign)?n:-n;}
//inline string readstring() {char c;while(c=getchar(),c==' '||c=='\n'||c=='\t');string s({c});while(c=getchar(),c!=EOF&&c!=' '&&c!='\n'&&c!='\t')s+=c;return s;}
 
// hết phần lộn xào rồi, vào main code thoi :v
 
/* Không theo thuật toán nhưng học vì nó vui
                                -Lê Quý Long- */
 
ll n,k,t;
unordered_map<ll,bool> kt;

struct matrix
{
    ll a[12][12] = {0};
};

unordered_map<ll,matrix> m;
matrix x, dv;

matrix nhan(matrix x, matrix y)
{
    matrix res;
    FOR(i,1,n,1) 
    {
        FOR(j,1,n,1) 
        {
            FOR(k,1,n,1) res.a[i][j] += (x.a[i][k]%MOD) * (y.a[k][j]%MOD) %MOD;
            res.a[i][j] = res.a[i][j]%MOD;
        }
    }

    return res;
}

matrix lt(matrix x, ll n)
{
    if(n == 0) return dv;

    if(kt[n]) return m[n];

    if(n%2 == 0)
    {
        m[n] = nhan(lt(x, n/2),lt(x, n/2));
        kt[n] = 1;
        return m[n];
    }
    else 
    {
        m[n] = nhan(nhan(lt(x, n/2),lt(x, n/2)),x);
        kt[n] = 1;
        return m[n];
    }
}

int main()
{
    	fast_cin 	
	//freopen("TEST.INP", "r", stdin);
	//freopen("TEST.OUT", "w", stdout);

    FOR(i,1,10,1)
    {
        dv.a[i][i] = 1;
    }

    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        FOR(i,1,n,1) 
        {
            FOR(j,1,n,1) cin >> x.a[i][j];
        }

        x = lt(x,k);

        ll sum = 0;
        FOR(i,1,n,1)
        {
            sum += x.a[i][n]%MOD;
        }

        cout << sum%MOD << '\n';

        kt.clear();
        m.clear();
    }

	return 0;
}