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

int t, n;

// Toi uu: sang nguyen to de phan tich thua so nguyen to nhanh => sinh uoc nhanh

int BFS() 
{
    queue<int> q;
    unordered_map<int,bool> m;

    q.push(n);
    m[n] = 1;

    int cnt = 0;

    while(!q.empty()) 
    {
        vector<int> x;

        while(!q.empty()) 
        {
            int s = q.front(); q.pop();

            if(s == 1) return cnt;
            x.pb(s);     
        }

        for(auto it : x) 
        {
            if(it == 1) return cnt;

            if(m[it-1] == 0) 
            {
                m[it-1] = 1;
                q.push(it-1);
            }

            FOR(i,2,sqrt(it),1) if(it%i == 0) 
            {
                if(m[it/i] == 0) 
                {    
                        m[it/i] = 1;
                        q.push(it/i);
                }
            }
        }

        cnt++;
    }

    return 0;
}
    
int main()
{   
    fast_cin
    cin >> t;
    while(t--)
    {
        cin >> n;
        cout << BFS() << '\n';
    }
    
    return 0;
}