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

bool issrt(int n) {
    int m1 = 0, m2 = 100, mid = 0;
    while (m2 - m1 > 1) {
        mid = (m1 + m2) / 2;
        if (mid * mid <= n)
            m1 = mid;
        else
            m2 = mid;
    }
    if (m1 * m1 == n)
        return true;
    else
        return false;
}

int srt(int n) {
    int m1 = 0, m2 = 100, mid = 0;
    while (m2 - m1 > 1) {
        mid = (m1 + m2) / 2;
        if (mid * mid <= n)
            m1 = mid;
        else
            m2 = mid;
    }
    return m1;
}

int dotP(vector<int> a, vector<int> b) {
    return a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
}

vector<int> crossP(vector<int> a, vector<int> b) {
    return {a[1] * b[2] - b[1] * a[2], b[0] * a[2] - b[2] * a[0],
            a[0] * b[1] - a[1] * b[0]};
}

double norm(vector<int> a) {
    return sqrt(a[0] * a[0] + a[1] * a[1] + a[2] * a[2]);
}

int box(vector<int> a, vector<int> b, vector<int> c) {
    return abs(dotP(a, crossP(b, c)));
}

double solidAngle(vector<int> a, vector<int> b, vector<int> c, double rad) {
    return abs(
        2 * atan(double(box(a, b, c)) /
                 (rad * (rad * rad + dotP(a, b) + dotP(a, c) + dotP(b, c)))));
}

void printp(vector<int> a) {
    cout << a[0] << ' ' << a[1] << ' ' << a[2] << '\n';
}

int main() {
    // freopen("./input.txt", "r", stdin);

    cout << fixed << setprecision(10);

    map<int, vector<vector<int>>> plist;

    int mrad = 50;

    for (int i = -mrad; i <= mrad; i++)
        for (int j = -mrad; j <= mrad; j++)
            for (int k = 0; k <= mrad; k++)
                if (issrt(i * i + j * j + k * k) &&
                    srt(i * i + j * j + k * k) <= mrad)
                    plist[srt(i * i + j * j + k * k)].push_back({i, j, k});

    double fans = 0;
    vector<vector<int>> temp;

    for (int rad = 1; rad <= mrad; rad += 1) {
        double ans = 100;
        temp = plist[rad];
        for (int i = 0; i < temp.size(); i++)
            for (int j = i + 1; j < temp.size(); j++)
                for (int k = j + 1; k < temp.size(); k++) {
                    if (box(temp[i], temp[j], temp[k]) != 0)
                        ans = min(ans, solidAngle(temp[i], temp[j], temp[k],
                                                  double(rad)));
                }
        cout << rad << '\n';

        fans += ans * double(rad * rad);
        cout << ans * double(rad * rad) << '\n';
    }
    cout << fans << '\n';
    return 0;
}