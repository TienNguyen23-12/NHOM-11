#include <bits/stdc++.h>
using namespace std;

#define ll long long


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
    cout << "Bang chan tri cua   (P --> Q) v R" << "\n";
    cout << "P Q R   (P --> Q)   (P --> Q) v R"<< "\n";
    ll P, Q, R, e, f;
    for (ll P = 0; P <= 1; ++P)
    {
	
        for (ll Q = 0; Q <= 1; ++Q)
        {
            for (ll R = 0; R <= 1; ++R)
			{
                if ((P == 0 && Q == 0) || (P == 0 && Q == 1) || (P == 1 && Q == 1))
				{
                    e = 1;
                    f = 1;
                    cout << P << " " << Q << " " << R << "       " << e << "             " << f << "\n";
                }
                if (P == 1 && Q == 0)
				{
                    e = 0;
                    if(R == 1) f = 1;
                    else f = 0;
                    cout << P << " " << Q << " " << R << "       " << e << "             " << f << "\n";
                }
            }
        }
	}
    return 0;
}


