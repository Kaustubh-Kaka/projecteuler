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

int dfs(int a[10], int n) {
    int ans = 0;
    while (n) {
        ans += a[n % 10];
        n /= 10;
    }
    return ans;
}

int main() {
    // freopen("./input.txt", "r", stdin);

    int dfac[10];
    dfac[0] = 1;
    for (int i = 1; i < 10; i++) dfac[i] = dfac[i - 1] * i;

    int ans = 0;
    int lim = int(2.4e6);
    for (int i = 9; i < lim; i++)
        if (dfs(dfac, i) == i) ans += i;

    cout << ans << '\n';
    return 0;
}