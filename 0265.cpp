#include <algorithm>
#include <chrono>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <vector>
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

    int n = 5;
    vector<int> a;
    for (int i = 0; i < (1 << (n - 1)) - n; i++) a.push_back(0);
    for (int i = 0; i < (1 << (n - 1)); i++) a.push_back(1);
    int it = 13037895;  // (1<<n)-nC(1<<(n-1))
    bool good = false;
    deque<int> chk;
    set<deque<int>> unq;
    int cnt = 0;
    vector<vector<int>> ans;
    while (it--) {
        good = true;
        chk = {};
        for (int i = 0; i < n; i++) chk.push_back(0);
        unq = {};
        unq.insert(chk);
        for (int i = 0; i < (1 << n) - n; i++) {
            chk.pop_front();
            chk.push_back(a[i]);
            if (unq.find(chk) != unq.end()) {
                good = false;
                break;
            } else
                unq.insert(chk);
        }
        if (good) {
            cnt++;
            ans.push_back(a);
        }
        next_permutation(a.begin(), a.end());
    }
    cout << cnt << '\n';
    ll fans = 0, cans = 0;
    for (int i = 0; i < ans.size(); i++) {
        cans = 0;
        for (int j = 0; j < ans[i].size(); j++)
            cans += (1 << j) * ans[i][ans[i].size() - 1 - j];
        fans += cans;
    }
    cout << fans << '\n';
    return 0;
}