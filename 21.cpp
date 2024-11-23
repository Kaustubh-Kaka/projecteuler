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

    int n = int(1e4);

    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; i++)
        for (int j = 2; i * j <= n; j++) a[i * j] += i;

    int ans = 0;

    for (int i = 0; i <= n; i++)
        if (a[i] <= n && a[a[i]] == i && a[i] != i) ans += i;

    cout << ans << '\n';
    return 0;
}