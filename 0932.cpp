#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;

const ll INF = 1e16;
const double eps = 1e-15;

void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main() {
    fast();
    // freopen("./input.txt", "r", stdin);

    ll n1 = 0, n2 = 0, tm = 0, ans = 0;
    bool good = false;
    for (ll i = 0; i < (1e8); i++) {
        good = false;
        n1 = i * i, n2 = 0, tm = 1;
        while (n1) {
            if (n1 + n2 == i) {
                good = true;
                break;
            }
            while ((n1 % 10) == 0) {
                n2 += tm * (n1 % 10);
                n1 /= 10;
                tm *= 10;
            }
            n2 += tm * (n1 % 10);
            n1 /= 10;
            tm *= 10;
        }
        if (good) ans += i * i;
    }
    cout << ans - 1 << '\n';
    return 0;
}