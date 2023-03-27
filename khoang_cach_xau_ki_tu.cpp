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
string st, en;
string a[100001];
unordered_set<string> ust;

ll BFS() 
{
    queue<string> q;
    
    ll cnt = 1;
    q.push(st);
    
    while(!q.empty())
    {
        vector<string> v;
        
        while(!q.empty()) 
        {
            string it = q.front();

            if(it == en) return cnt;

            v.push_back(it);
            q.pop();
        }

        for(string &it : v) 
        {         
            ust.erase(st);
            ll len = it.size()-1;
            
            FOR(i,0,len,1) 
            {
                char x = it[i];

                FOR(j,'A','Z',1) 
                {
                    it[i] = j;

                    if(ust.find(it) != ust.end()) 
                    {
                        ust.erase(it);
                        q.push(it);
                    } 
                }

                it[i] = x;
            }
        }

        cnt++;
    }

    return -1;
}
    
int main()
{   
    fast_cin

    cin >> t;
    while(t--)
    {
        cin >> n >> st >> en;
        FOR(i,1,n,1) 
        {
            cin >> a[i];
            ust.insert(a[i]);
        }

        cout << BFS() << '\n';

        ust.clear();
    }
    
    return 0;
}