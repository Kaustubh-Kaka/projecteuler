#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main() {
    // freopen("./input.txt", "r", stdin);

    ll k = 1e3;

    ll b = 0, c = 0;

    for (ll a = 1; a <= k / 3; a++) {
        if ((k * a) % (2 * (k - a)) == 0) {
            b = (k * (k - 2 * a)) / (2 * (k - a));
            c = k - a - b;
            cout << a << ' ' << b << ' ' << c << ' ' << a * b * c << '\n';
        }
    }

    return 0;
}