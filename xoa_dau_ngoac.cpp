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

ll t, n, cnt;
pair<ll,ll> a[500];
string s;
set<string> res;
bool kt[500];
stack<ll> st;

void Display()
{
    string tmp = "";
    FOR(i,0,n,1) 
    {
        if(kt[i] == 0) tmp+= s[i]; 
    }
    res.insert(tmp);
}

bool check(string s)
{
    ll len = s.size() - 1;
    FOR(i,0,len,1) if(s[i] == '/' && s[i+1] == '0') return 0;
    return 1;
}

void Solve(ll i) 
{
    FOR(j,0,1,1) 
    {
        if(j == 1) 
        {
            kt[a[i].first] = 1;
            kt[a[i].second] = 1;
        } 

        if(i < cnt) 
        {
            Solve(i+1);
        }
        else Display();

        if(j == 1) 
        {
            kt[a[i].first] = 0;
            kt[a[i].second] = 0;
        }     
    }
}
    
int main()
{   
    fast_cin

    cin >> s;
    n = s.size() - 1;

    ll l = 0, r = n;
    cnt = 0;
    
    FOR(i,0,n,1) 
    {
        if(s[i] == '(') st.push(i);
        else if(s[i] == ')') 
        {
            a[++cnt] = make_pair(st.top(),i);
            st.pop();
        }
    }
    

    Solve(1);

    for(auto it : res) if(check(it) && it != s) cout << it << '\n';
 
    return 0;
}