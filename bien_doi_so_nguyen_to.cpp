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

ll t, st, en;

ll prime[10001] = {0};
void Sieve(ll n)
{
    prime[2] = 1;
    FOR(i,3,n,2) prime[i] = 1;
    FOR(i,3,n,2)
    {
        if(prime[i]) 
        {
            FOR(j,i*3,n,i*2) prime[j] = 0;
        }
    }
}

ll BFS() 
{
    queue<ll> q;
    unordered_map<ll,bool> m;
    
    ll cnt = 0;
    q.push(st);
    
    while(!q.empty())
    {
        vector<ll> v;
        
        while(!q.empty()) 
        {
            v.push_back(q.front());
            q.pop();
        }

        for(auto it : v) 
        {
            if(it == en) return cnt;
            string s = to_string(it);           

            FOR(i,0,3,1) 
            {
                FOR(j,'0','9',1) 
                {
                    if(i == 0 && j == '0') continue;
                    if(i == 3 && j % 2 == 0) continue;

                    if(s[i] != j) 
                    {
                        string ans = s;

                        ans[i] = j;
                        ll tmp = stoll(ans);                       

                        if(prime[tmp] && m[tmp] == 0) 
                        {
                            m[tmp] = 1;
                            q.push(tmp);                        
                        } 
                    }
                }
            }
        }

        cnt++;
    }

    return -1;
}
    
int main()
{   
    fast_cin

    Sieve(1e4);

    cin >> t;
    while(t--)
    {
        cin >> st >> en;
        cout << BFS() << '\n';
    }
    
    return 0;
}