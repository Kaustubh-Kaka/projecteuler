#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<vector<ll>> vvi;

void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main() {
    fast();
    // freopen("./input.txt", "r", stdin);

    double tg = double(15499) / double(94744);

    ll tfn = 15499, tfdn = 94744;

    const int n = 1e3;
    vector<int> primes;
    vector<bool> erat(n + 1, true);

    for (int i = 2; i * i <= n; i++)
        for (int j = 2; i * j <= n; j++) erat[i * j] = false;

    for (int i = 2; i <= n; i++)
        if (erat[i]) primes.push_back(i);

    // cout << fixed << setprecision(10) << '\n';

    double f = 1;
    int ind = 0;
    double val = 1;
    ll acfn = 1, acfd = 1;
    while (f > tg) {
        f *= double(primes[ind] - 1) / double(primes[ind]),
            val *= double(primes[ind]), acfn *= ll(primes[ind] - 1),
            acfd *= ll(primes[ind]);

        ind++;
        // cout << acfn * tfdn << ' ' << (acfd - 1) * tfn << ' ' << acfn << ' '
        //      << acfd << ' ' << double(acfn) / double(acfd - 1) << '\n';
        // cout << f << ' ' << f / (1.0 - (1.0 / val)) << ' ' << tg << '\n';
    }

    for (int j = 1; j < 29; j++)
        if (j * acfn * tfdn < (j * acfd - 1) * tfn) {
            cout << j * acfd << '\n';
            break;
        }
    return 0;
}
