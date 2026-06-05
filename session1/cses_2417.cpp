#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    const int MX = 1000000;

    vector<int> freq(MX + 1);

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        freq[x]++;
    }

    // Mobius function
    vector<int> mu(MX + 1, 1);
    vector<int> prime;
    vector<bool> isPrime(MX + 1, true);

    mu[0] = 0;
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i <= MX; i++) {
        if (isPrime[i]) {
            prime.push_back(i);
            mu[i] = -1;
        }

        for (int p : prime) {
            if (1LL * i * p > MX) break;

            isPrime[i * p] = false;

            if (i % p == 0) {
                mu[i * p] = 0;
                break;
            } else {
                mu[i * p] = -mu[i];
            }
        }
    }

    vector<int> divCnt(MX + 1);

    for (int d = 1; d <= MX; d++) {
        for (int multiple = d; multiple <= MX; multiple += d) {
            divCnt[d] += freq[multiple];
        }
    }

    long long notCoprimePairs = 0;

    for (int d = 2; d <= MX; d++) {
        if (mu[d] == 0) continue;

        long long c = divCnt[d];

        notCoprimePairs += 1LL * mu[d] * c * (c - 1) / 2;
    }

    long long totalPairs = 1LL * n * (n - 1) / 2;

    long long coprimePairs = totalPairs + notCoprimePairs;

    cout << coprimePairs << '\n';
}