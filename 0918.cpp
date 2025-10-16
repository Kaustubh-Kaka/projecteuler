#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;
typedef vector<vector<ll>> vvi;

void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

ll af(ll n) {
    if (n == 1)
        return 1;
    else if (__builtin_popcount(n) == 1)
        return n;
    else {
        ll fac = 1;
        while (n % 2 == 0) {
            n /= 2;
            fac *= 2;
        }
        return fac * (af(n / 2) - 3 * af(n / 2 + 1));
    }
}

ll sf(ll n) {
    if (n == 1)
        return 1;
    else if (n % 2)
        return 4ll - 3ll * af(n / 2 + 1);
    else
        return 4ll - af(n / 2);
}

int main() {
    fast();
    // freopen("./input.txt", "r", stdin);

    cout << sf(ll(1e12)) << '\n';

    return 0;
}
