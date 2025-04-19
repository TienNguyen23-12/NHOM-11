#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n, m, root;
vector<vector<ll>> ke;      
vector<ll> chuaXet;      
vector<pair<ll, ll>> t; 

void nhapdothi()
{
    for (ll i = 0; i < m; ++i)
    {
        ll u, v;
        cin >> u >> v;
        ke[u].push_back(v);
        ke[v].push_back(u);
    }
}

void tree_BFS(ll r)
{
    queue<ll> QUEUE;
    QUEUE.push(r);
    chuaXet[r] = 0;

    while (!QUEUE.empty())
    {
        ll v = QUEUE.front();
        QUEUE.pop();

        sort(ke[v].begin(), ke[v].end()); 
        for (ll u : ke[v])
        {
            if (chuaXet[u] == 1)
            {
                QUEUE.push(u);
                chuaXet[u] = 0;
                t.push_back({v, u});
                
            }
        }
    }
}

int main()
{
	freopen("Bai-5.input.txt", "r", stdin);
//    freopen("OUTPUT/output.txt", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> root;
	
	ke.resize(n + 1);
    chuaXet.resize(n + 1, 1);
    t.clear();
    
	nhapdothi();
	
	tree_BFS(root);
	
	cout << "Cac canh cua cay khung:\n";
    for (auto x : t) cout << x.first << " - " << x.second << endl;

	return 0;
}



