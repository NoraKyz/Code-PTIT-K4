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
bool kt = 0;

struct Node
{
    ll value;
    Node *left, *right;
};

typedef Node* binTree;

binTree createNode(ll c) 
{
    binTree res = new Node;
    res -> value = c;
    res -> left = res -> right = NULL;

    return res;
} 

ll Solve(binTree root, char c) 
{
    if(root == NULL) return 0;

    if(root -> left == NULL && root -> right == NULL) 
    {
        if(c == 'R') return root -> value;
        return 0;
    }
    
    return Solve(root -> left, 'L') + Solve(root -> right, 'R');   
} 

int main()
{   
    fast_cin
    cin >> t;
    while(t--)
    {
        ll par, child;
        char c;

        cin >> n;
        
        unordered_map<int, binTree> m;
        cin >> par >> child >> c;
        binTree root = createNode(par);
        if(c == 'L')
        {
            root -> left = createNode(child);
            m[child] = root -> left;
        }
        else
        {
            root -> right = createNode(child);
            m[child] = root -> right;
        }
        m[par] = root;
        n--;

        while(n--)
        {
            cin >> par >> child >> c;
            if(c == 'L')
            {
                m[par] -> left = createNode(child);
                m[child] = m[par] -> left;
            }
            else
            {
                m[par] -> right = createNode(child);
                m[child] = m[par] -> right;
            }
        }

        cout << Solve(root, 'L') << '\n';
    }
    
    return 0;
}