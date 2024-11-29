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

    int nmax = 1e2;
    vector<bool> erat(nmax + 1, true);
    vector<int> plist;

    for (int i = 2; i * i <= nmax; i++)
        if (erat[i])
            for (int j = 2; i * j <= nmax; j++) erat[i * j] = false;

    for (int i = 2; i < nmax; i++)
        if (erat[i]) plist.push_back(i);

    vector<vector<int>> dp(nmax + 1, vector<int>(plist.size() + 1, 0));
    dp[0][0] = 1;
    for (int i = 0; i <= nmax; i++) {
        for (int j = 0; j < plist.size(); j++) {
            dp[i][j + 1] = dp[i][j];
            // if (plist[j] > i) break;
            for (int k = 1; plist[j] * k <= i; k++) {
                dp[i][j + 1] += dp[i - k * plist[j]][j];
            }
        }
    }
    for (int i = 0; i < dp.size(); i++) {
        if (dp[i][plist.size()] > int(5e3)) {
            cout << i << '\n';
            break;
        }
    }
    return 0;
}

// use unique coin combination dp to solve in O(n) instead of O(n*π(n))