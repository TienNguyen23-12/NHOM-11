#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll INF = 100;


void print_res(ll v, ll truoc[]) 
{
    if (truoc[v] == -1) 
	{
        cout << v << " ";
        return;
    }
    print_res(truoc[v], truoc);
    cout << v << " ";
}

void BellmanFord(ll a[][INF], ll n, ll s) 
{
    ll d[INF], truoc[INF];

    for (ll v = 0; v < n; ++v) 
	{
        d[v] = a[s][v];
        truoc[v] = s;
    }
    
    d[s] = 0;
    truoc[s] = -1;

    for (ll k = 1; k < n; ++k) 
    {
        for (ll v = n - 1; v >= 0; --v) 
        {
            if (v == s) continue;
            for (ll u = 0; u < n; ++u) 
            {
				if (d[v] > d[u] + a[u][v]) 
                {
                    d[v] = d[u] + a[u][v];
                    truoc[v] = u;
                }
            }
        }
    }
    
    truoc[0] = -1;

    for (ll v = 0; v < n; ++v) 
	{
        cout << "d[" << v << "] = ";
        if (d[v] >= INF) cout << INF;
        else 
        {
        	if(d[v] < 0) cout << d[v];
        	else cout << ' ' << d[v];
		}
        cout << " | Duong di tu " << s << " den " << v << ": " ;
        if (d[v] < INF && truoc[v] != -1) print_res(v, truoc);
        cout << "\n";
    }
}

int main() 
{
    freopen("Bai-4.input.txt", "r", stdin);
    ll s, n;
    cin >> s >> n;
    ll a[INF][INF];
    for (ll i = 0; i < n; ++i)
    {
        for (ll j = 0; j < n; ++j) 
		{
            cin >> a[i][j];
            if (a[i][j] == 0) a[i][j] = INF;
        }
    }

    BellmanFord(a, n, s);
    return 0;
}

