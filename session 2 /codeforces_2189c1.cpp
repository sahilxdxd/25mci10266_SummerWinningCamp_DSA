#include <bits/stdc++.h>
using namespace std;

bool valid(const vector<int>& p, int n) {
    for (int i = 2; i <= n - 1; i++) {
        bool found = false;

        for (int j = i; j <= n; j++) {
            if (p[i - 1] == (p[j - 1] ^ i)) {
                found = true;
                break;
            }
        }

        if (!found) return false;
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<int> p(n);
        iota(p.begin(), p.end(), 1);

        bool found = false;

        do {
            if (valid(p, n)) {
                for (int x : p)
                    cout << x << ' ';
                cout << '\n';

                found = true;
                break;
            }
        } while (next_permutation(p.begin(), p.end()));

        if (!found)
            cout << "-1\n";
    }

    return 0;
}
