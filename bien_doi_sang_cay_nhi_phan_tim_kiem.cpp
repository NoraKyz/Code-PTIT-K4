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
ll a[100001];

struct Node
{
    ll value;
    Node *left, *right;
};

typedef Node* binTree;

binTree createNode(ll value)
{
    binTree parent = new Node;

    parent -> value = value;
    parent -> left = parent -> right = NULL;

    return parent;
}

void buildTree(binTree &parent, ll par, ll child, char c)
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

        buildTree(parent -> left, par, child, c);
        buildTree(parent -> right, par, child, c);
    }
}

void convertTree(binTree &root) 
{
    if(root != NULL) 
    {
        convertTree(root -> left);
        root -> value = a[cnt++];
        convertTree(root -> right);
    }
}

void inOrder(binTree root) 
{
    if(root != NULL) 
    {
        inOrder(root -> left);
        cout << root -> value << " ";
        inOrder(root -> right);
    }
}

// sap xep mang cho tang dan -> phep duyet inOrder cua BST
    
int main()
{   
    fast_cin
    cin >> t;
    while(t--)
    {
        cin >> n;

        ll par, child;
        char c;

        cin >> par >> child >> c;
        binTree root = createNode(par);
        buildTree(root, par, child, c);
        n--;

        a[1] = par;
        a[2] = child;
        cnt = 2;

        while(n--)
        {
            cin >> par >> child >> c;
            buildTree(root, par, child, c);
            a[++cnt] = child;
        }

        sort(a+1,a+1+cnt);

        cnt = 1;
        convertTree(root);
        inOrder(root);

        cout << '\n';
    }
    
    return 0;
}