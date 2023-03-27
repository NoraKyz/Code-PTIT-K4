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
    
    ll cnt = 0;
    q.push(st);
    m[st] = 1;
    
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

        for(auto it : v) 
        {
            // 123456 2->5 153426 3->5 152436 6->5 152463  
            // 123456 2->5 153426 2->4 143526 2->1 213526 
            string a = it, b = it;

            swap(a[1],a[4]); swap(a[2],a[4]); swap(a[5],a[4]);
            swap(b[1],b[4]); swap(b[1],b[3]); swap(b[1],b[0]);

            if(m[a] == 0) 
            {
                m[a] = 1;
                q.push(a);
            }

            if(m[b] == 0) 
            {
                m[b] = 1;
                q.push(b);
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
        st = ""; en = "";

        FOR(i,1,6,1) 
        {
            cin >> x;
            st += x + '0';
        }

        FOR(i,1,6,1) 
        {
            cin >> x;
            en += x + '0';
        }

        cout << BFS() << '\n';
    }
    
    return 0;
}