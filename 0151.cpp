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

    auto start = high_resolution_clock::now();

    vector<int> temp;
    map<vector<int>, double> m1, m2;
    m1 = {{{1}, 1.0}};
    int it = 16;
    double ans = 0;
    while (it--) {
        for (auto x : m1) {
            if (x.first.size() == 1) ans += x.second;
            for (int j = 0; j < x.first.size(); j++) {
                temp = x.first;
                if (x.first[j] != 5)
                    for (int k = x.first[j] + 1; k <= 5; k++) temp.push_back(k);
                swap(temp[temp.size() - 1], temp[j]);
                temp.pop_back();
                m2[temp] += x.second / double(x.first.size());
            }
        }
        m1 = m2;
        m2 = {};
    }

    auto stop = high_resolution_clock::now();
    auto dur = duration_cast<microseconds>(stop - start);

    cout << fixed << setprecision(6) << ans - 2 << ' ' << dur.count() << "µs\n";

    return 0;
}