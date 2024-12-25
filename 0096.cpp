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
typedef vector<vector<ll>> vvi;

void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

const int N = 9;

int steps = 0;

bool solve(int a[N][N]) {
    // steps++;
    bool good = true;

    int zc = 0;
    bool digs[N];
    int bi, bj;
    vector<int> posdigs = {}, bposdigs = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (a[i][j] == 0) {
                zc++;
                for (int k = 0; k < N; k++) digs[k] = true;
                posdigs = {};
                for (int k = 0; k < N; k++)
                    if (a[k][j] != 0) digs[a[k][j] - 1] = false;

                for (int k = 0; k < N; k++)
                    if (a[i][k] != 0) digs[a[i][k] - 1] = false;

                for (int k = 0; k < N / 3; k++)
                    for (int l = 0; l < N / 3; l++)
                        if (a[3 * (i / 3) + k][3 * (j / 3) + l] != 0)
                            digs[a[3 * (i / 3) + k][3 * (j / 3) + l] - 1] =
                                false;

                for (int k = 0; k < N; k++)
                    if (digs[k]) posdigs.push_back(k + 1);
                if (posdigs.size() == 0) {
                    good = false;
                    break;
                }
                if (posdigs.size() < bposdigs.size()) {
                    bposdigs = posdigs;
                    bi = i;
                    bj = j;
                }
            }
        }
        if (!good) break;
    }

    if (!good)
        return false;
    else {
        if (zc == 0)
            return true;
        else {
            bool found = false;
            for (int i = 0; i < bposdigs.size(); i++) {
                a[bi][bj] = bposdigs[i];
                if (!solve(a))
                    a[bi][bj] = 0;
                else {
                    found = true;
                    break;
                }
            }
            return found;
        }
    }
}

int main() {
    fast();
    // freopen("./input.txt", "r", stdin);

    ifstream in;
    in.open("./0096data.txt");

    int ans = 0;
    string gno;
    int a[N][N];
    while (getline(in, gno)) {
        string s;
        for (int i = 0; i < N; i++) {
            getline(in, s);
            for (int j = 0; j < N; j++) {
                a[i][j] = s[j] - '0';
            }
        }

        bool solvable = solve(a);
        // cout << gno << '\n';
        // for (int i = 0; i < N; i++) {
        //     for (int j = 0; j < N; j++) cout << a[i][j] << ' ';
        //     cout << '\n';
        // }
        // cout << steps << '\n';
        // steps = 0;
        ans += a[0][0] * 100 + a[0][1] * 10 + a[0][2];
    }
    cout << ans << '\n';
    return 0;
}
