#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()

typedef long long ll;
typedef pair<ll, ll> pii;
typedef complex<double> cd;

void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
    fast();

    vector<double> a;

    int aa = 100, bb = 100;

    double tval, eps = 1e-8;

    bool ex = false;

    for (int i = 2; i <= aa; i++)
        for (int j = 2; j <= bb; j++) {
            ex = false;
            tval = j * log(i);

            for (int k = 0; k < a.size(); k++)
                if (abs(tval - a[k]) < eps) ex = true;
            if (!ex) a.push_back(tval);
        }
    cout << a.size() << '\n';

    return 0;
}