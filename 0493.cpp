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
using namespace std::chrono;

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

    vector<__int128_t> tcr = {1, 10, 45, 120, 210, 252, 210, 120, 45, 10, 1};

    __int128_t num = 11 * 11 * 11 * 11 * 11 * 11 * 11;
    __int128_t dsum = 0, col = 0, tc = 0, temp = 0, ans = 0, fac = 1;
    for (int i = 0; i < num; i++) {
        fac = 1;
        temp = i;
        dsum = 0;
        col = 0;
        while (temp) {
            dsum += temp % 11;
            fac *= tcr[(temp % 11)];
            if (temp % 11) col++;
            temp /= 11;
        }
        if (dsum == 20) {
            tc += fac;
            ans += col * fac;
        }
    }
    cout << fixed << setprecision(10);
    cout << double(ans) << ' ' << double(tc) << ' ' << double(ans) / double(tc)
         << '\n';
    return 0;
}
