#include <chrono>
#include <fstream>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
using namespace std::chrono;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;

void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

map<pii, ll> plmemo;

ll pathlength(ll root, ll tgt) {
    if (root == tgt)
        return 1;
    else {
        if (!plmemo[{root, tgt}]) {
            if ((root - tgt) % 2)
                plmemo[{root, tgt}] = 1 + pathlength(root / 2, (tgt + 1) / 2);
            else
                plmemo[{root, tgt}] = pathlength((root + 1) / 2, (tgt + 1) / 2);
        }
        return plmemo[{root, tgt}];
    }
}

ll recans(ll root, ll tgt) {
    if (root == tgt)
        return root;
    else if ((root - tgt) % 2) {
        if (root % 2)
            return root + 2 * recans((root - 1) / 2, tgt / 2);
        else
            return root + 2 * recans(root / 2, (tgt + 1) / 2) -
                   pathlength(root / 2, (tgt + 1) / 2);
    } else {
        if (root % 2)
            return 2 * recans((root + 1) / 2, (tgt + 1) / 2) -
                   pathlength((root + 1) / 2, (tgt + 1) / 2);
        else
            return 2 * recans(root / 2, tgt / 2);
    }
}

ll mexp(ll a, ll x) {
    ll ans = 1;
    for (int i = 0; i < x; i++) ans *= a;
    return ans;
}

int main() {
    fast();

    // freopen("./input.txt", "r", stdin);

    auto start = high_resolution_clock::now();

    ll a = mexp(10, 17), b = mexp(9, 17);
    cout << recans(a, b) << '\n';

    auto stop = high_resolution_clock::now();
    auto dur = duration_cast<nanoseconds>(stop - start);
    cout << dur.count() << "ns\n";

    return 0;
}