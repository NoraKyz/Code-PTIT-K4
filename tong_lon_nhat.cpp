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
ll res = -1e9;
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
            return;
        }
        buildTree(parent -> left, c, par, child);
        buildTree(parent -> right, c, par, child);
    } 
}

ll findMax(binTree a) 
{
    if(a == NULL) return 0;

    ll L = findMax(a -> left), R = findMax(a -> right); // tim duong di tot nhat tu node la toi node trung gian dang xet
    
    if(a -> left == NULL && a -> right == NULL) // a la node la
        return a -> value;

    // a la node trung gian
    if(a -> left == NULL) 
        return R + a -> value;
    if(a -> right == NULL)
        return L + a -> value;

    res = max(res, L + R + a -> value); // duong di max tu node la L -> a -> node la R

    return max(R,L) + a -> value; // duong di max tu node la toi node trung gian a
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
        binTree root = createNode(par);
        buildTree(root, c, par, child);
        
        FOR(i,2,n,1) 
        {
            cin >> par >> child >> c;
            buildTree(root, c, par, child);
        }

        res = -1e9;
        findMax(root);
        
        cout << res << '\n';
    }
    
    return 0;
}