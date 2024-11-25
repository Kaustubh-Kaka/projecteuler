#include <algorithm>
#include <chrono>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
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

    vector<pii> a = {{2, 1}};

    while (a.size() < 20)
        a.push_back({2 * a[a.size() - 1].first + 3 * a[a.size() - 1].second,
                     a[a.size() - 1].first + 2 * a[a.size() - 1].second});

    // for (int i = 0; i < a.size(); i++)
    //     cout << a[i].first << ' ' << a[i].second << '\n';

    ll ans = 0;

    for (int i = 0; i < a.size(); i++) {
        if ((2 * a[i].first - 1) % 3 == 0) {
            // cout << "a " << (2 * a[i].first - 1) / 3 << ' ' << 2 *
            // a[i].second
            //      << '\n';
            if ((2 * a[i].first - 1) / 3 > 1 && (2 * a[i].first - 2) < ll(1e9))
                ans += 2 * a[i].first - 2;
        }
        if ((2 * a[i].first + 1) % 3 == 0) {
            // cout << "b " << (2 * a[i].first + 1) / 3 << ' ' << 2 *
            // a[i].second
            //      << '\n';
            if ((2 * a[i].first + 2) < ll(1e9)) ans += 2 * a[i].first + 2;
        }
    }

    cout << ans << '\n';

    return 0;
}