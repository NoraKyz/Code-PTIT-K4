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

ll t, x;
string st, en;

ll BFS() 
{
    queue<string> q;
    unordered_map<string,bool> m;
    queue<string> p;
    unordered_map<string,bool> n;
    
    ll cnt = 0, dnt = 0;
    q.push(st);
    p.push(en);
    m[st] = 1;
    n[en] = 1;
    
    while(!q.empty() && !p.empty())
    {
        vector<string> v;
        vector<string> u;
        
        while(!q.empty()) 
        {
            string it = q.front();
            v.push_back(it);
            q.pop();
        }

        while(!p.empty()) 
        {
            string it = p.front();
            u.push_back(it);
            p.pop();
        }

        cnt++;
        for(auto it : v) 
        {
            string a = it, b = it;

            char tmp = a[1];
            a[1] = a[4]; a[4] = a[8]; a[8] = a[9]; a[9] = a[6]; a[6] = a[2]; a[2] = tmp;
            tmp = b[0];
            b[0] = b[3]; b[3] = b[7]; b[7] = b[8]; b[8] = b[5]; b[5] = b[1]; b[1] = tmp;

            if(m[a] == 0) 
            {
                m[a] = 1;
                q.push(a);
                if(n[a]) return cnt + dnt;
            }

            if(m[b] == 0) 
            {
                m[b] = 1;
                q.push(b);
                if(n[b]) return cnt + dnt;
            }
        }

        dnt++;
        for(auto it : u) 
        {
            string a = it, b = it;

            char tmp = a[1];
            a[1] = a[2]; a[2] = a[6]; a[6] = a[9]; a[9] = a[8]; a[8] = a[4]; a[4] = tmp;
            tmp = b[0];
            b[0] = b[1]; b[1] = b[5]; b[5] = b[8]; b[8] = b[7]; b[7] = b[3]; b[3] = tmp;

            if(n[a] == 0) 
            {
                n[a] = 1;
                p.push(a);
                if(m[a]) return cnt + dnt;
            }

            if(n[b] == 0) 
            {
                n[b] = 1;
                p.push(b);
                if(m[b]) return cnt + dnt;
            }
        }
    }

    return -1;
}
    
int main()
{   
    fast_cin

    cin >> t;
    while(t--)
    {
        st = ""; en = "1238004765";

        FOR(i,1,10,1) 
        {
            cin >> x;
            st += x + '0';
        }

        cout << BFS() << '\n';
    }
    
    return 0;
}