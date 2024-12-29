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

    int n = 1e5;
    vector<int> ch;
    for (int i = 0; i < n; i++) ch.push_back(i + 1);
    vector<int> dp(n + 1, 0), tf(n + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < ch.size(); i++) {
        tf = dp;
        for (int j = ch[i]; j < tf.size(); j++) {
            tf[j] += tf[j - ch[i]];
            tf[j] %= int(1e6);
        }
        dp = tf;
    }
    for (int i = 0; i <= n; i++)
        if (dp[i] % 1000000 == 0) cout << i << '\n';

    return 0;
}