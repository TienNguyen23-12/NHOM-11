#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n;
vector<vector<ll>> adj;

void treo()
{
	for (ll i = 0; i < n; ++i) 
	{
        int tong = 0;
        for (ll j = 0; j < n; ++j) tong += adj[i][j];
        if (tong == 1) cout << i << ' ';
    }
    cout << "\n";
}

void colap()
{
	for (ll i = 0; i < n; ++i) 
	{
        ll tong = 0;
        for (ll j = 0; j < n; ++j) tong += adj[i][j];
        if (tong == 0) cout << i << ' ';
    }
    cout << "\n";
}

void songsong()
{
	for (ll i = 0; i < n; ++i)
	{
        for (ll j = 0; j < n; ++j)
		{
            if (adj[i][j] >= 2 && i != j) 
            {
            	cout << i << ' ' << j;
            	return ;
			}
        }
    }
}

int main()
{
	freopen("Bai-2.input.txt", "r", stdin);
//    freopen("OUTPUT/output.txt", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	adj.resize(n, vector<ll>(n));
	
	for (ll i = 0; i < n; ++i) for (ll j = 0; j < n; ++j) cin >> adj[i][j];
	
	cout << "Dinh treo: ";
	treo();
	
	cout << "Dinh co lap: ";
	colap();
	
	cout << "Cap dinh co canh //: ";
	songsong();
	
	
	

	return 0;
}



