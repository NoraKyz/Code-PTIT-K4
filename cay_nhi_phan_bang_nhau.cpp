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

void buildTree(binTree &parent, char c, ll par, ll child) 
{
    if(parent != NULL) 
    {
        if(parent -> value == par) 
        {
            if(c == 'L') 
                parent -> left = createNode(child);
            else 
                parent -> right = createNode(child);
        }
        buildTree(parent -> left, c, par, child);
        buildTree(parent -> right, c, par, child);
    } 
}

bool soSanh(binTree a, binTree b)
{
    if(a == NULL && b == NULL) return 1;

    if(a != NULL && b != NULL) 
    {
        return (a -> value == b -> value && soSanh(a -> left, b -> left) 
        && soSanh(a -> right, b -> right));
    }

    return 0;
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
        
        cin >> par >> child >> c;
        binTree root1 = createNode(par);
        buildTree(root1, c, par, child);
        
        FOR(i,2,n,1) 
        {
            cin >> par >> child >> c;
            buildTree(root1, c, par, child);
        }

        cin >> n;
        
        cin >> par >> child >> c;
        binTree root2 = createNode(par);
        buildTree(root2, c, par, child);
        
        FOR(i,2,n,1) 
        {
            cin >> par >> child >> c;
            buildTree(root2, c, par, child);
        }

        
        cout << soSanh(root1, root2) << '\n';
    }
    
    return 0;
}