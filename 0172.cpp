#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

typedef __int128_t ll;
typedef pair<ll, ll> pii;

void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

constexpr int msize = 35;

vector<vector<ll>> nCr(msize, vector<ll>(msize, 0));

void init() {
    for (int i = 0; i < msize; i++) nCr[i][0] = nCr[i][i] = 1;
    for (int i = 2; i < msize; i++)
        for (int j = 1; j < i; j++) {
            nCr[i][j] = nCr[i - 1][j] + nCr[i - 1][j - 1];
        }
}

vector<ll> mult(const vector<ll>& a, const vector<ll>& b) {
    vector<ll> c(a.size() + b.size() - 1, 0);
    for (int i = 0; i < a.size(); i++)
        for (int j = 0; j < b.size(); j++)
            c[i + j] += nCr[i + j][i] * a[i] * b[j];
    return c;
}

vector<ll> pow(const vector<ll> a, ll x) {
    vector<ll> ans = {1};
    for (int i = 0; i < x; i++) ans = mult(ans, a);
    return ans;
}

int main() {
    fast();

    auto start = high_resolution_clock::now();

    init();

    vector<ll> temp = mult({1, 1, 1}, pow({1, 1, 1, 1}, 9));
    cout << 9 * (long long)(temp[17]) << '\n';

    auto stop = high_resolution_clock::now();
    auto dur = duration_cast<microseconds>(stop - start);
    cout << dur.count() << "us\n";

    return 0;
}