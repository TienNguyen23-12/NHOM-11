#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll INF = 100;

void erase(ll T[], ll &t, ll u) 
{
    ll pos = -1;
    for (ll i = 0; i < t; ++i) if (T[i] == u) pos = i;
    
    if (pos == -1) return;

    for (ll i = pos; i < t - 1; ++i) T[i] = T[i + 1];
    --t;
}

ll find_min(ll T[], ll d[], ll t) 
{
    ll min_val = INF;
    ll min_pos = T[0];
    
    for (ll u = 0; u < t; ++u) 
	{
        if (d[T[u]] < min_val) 
		{
            min_val = d[T[u]];
            min_pos = T[u];
        }
    }
    return min_pos;
}

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

void Dijkstra(ll a[][INF], ll n, ll s) 
{
    ll d[INF], truoc[INF];
    ll T[INF], t = n;

    for (ll v = 0; v < n; ++v) 
	{
        d[v] = a[s][v];
        truoc[v] = s;
        T[v] = v;
    }
    d[s] = 0;
    truoc[s] = -1;
    erase(T, t, s);

    while (t != 0) 
	{
        ll u = find_min(T, d, t);
        erase(T, t, u);
        for (ll i = 0; i < t; ++i) 
		{
            ll v = T[i];
            if (d[v] > d[u] + a[u][v]) 
			{
                d[v] = d[u] + a[u][v];
                truoc[v] = u;
            }
        }
    }

    for (ll v = 0; v < n; ++v) 
	{
        cout << "d[" << v << "] = ";
        if (d[v] >= INF) cout << "INF";
        else cout << d[v];
        cout << " | Duong di tu " << s << " den " << v << ": " ;
        if (d[v] < INF) print_res(v, truoc);
        cout << "\n";
    }
}

int main() 
{
    freopen("Bai-3.input.txt", "r", stdin);
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

    Dijkstra(a, n, s);
    return 0;
}

