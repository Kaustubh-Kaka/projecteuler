#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

const int n = 1e6;
vector<bool> erat(n + 1, true);

int nd(int n) {
    int ans = 0;
    while (n) {
        ans++;
        n /= 10;
    }
    return ans;
}

bool circular(int n) {
    bool good = true;
    int tp = 1;
    while (tp < n) tp *= 10;
    tp /= 10;
    int rc = nd(n);
    for (int i = 0; i < rc; i++) {
        if (!erat[n]) {
            good = false;
            break;
        }
        n = tp * (n % 10) + n / 10;
    }
    return good;
}

int main() {
    // freopen("./input.txt", "r", stdin);

    for (int i = 2; i * i <= n; i++) {
        for (int j = 2; i * j <= n; j++) erat[i * j] = false;
    }

    ll ans = 0;
    for (int i = 2; i <= n; i++)
        if (erat[i] && circular(i)) ans++;
    cout << ans << '\n';

    return 0;
}