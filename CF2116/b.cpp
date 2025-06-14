#include <bits/stdc++.h>

const int maxn = 1e5 + 10, mod = 998244353;

int qpow(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = 1LL * res * a % mod;
        a = 1LL * a * a % mod;
        b >>= 1;
    }
    return res;
}

int main() {
    int t, n;
    int p[maxn], q[maxn];
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) scanf("%d", &p[i]);
        for (int i = 0; i < n; i++) scanf("%d", &q[i]);
        int maxp = -1, maxq = -1, maxp_idx = -1, maxq_idx = -1, ans;
        for (int i = 0; i < n; i++) {
            if (p[i] > maxp) {
                maxp = p[i];
                maxp_idx = i;
            }
            if (q[i] > maxq) {
                maxq = q[i];
                maxq_idx = i;
            }
            if (maxp > maxq) {
                ans = 1LL * (qpow(2, maxp) + qpow(2, q[i - maxp_idx])) % mod;
            }
            else if (maxp < maxq) {
                ans = 1LL * (qpow(2, maxq) + qpow(2, p[i - maxq_idx])) % mod;
            }
            else {
                if (q[i - maxp_idx] < p[i - maxq_idx]) {
                    ans = 1LL * (qpow(2, maxq) + qpow(2, p[i - maxq_idx])) % mod;
                } else {
                    ans = 1LL * (qpow(2, maxp) + qpow(2, q[i - maxp_idx])) % mod;
                } 
            }
            printf("%d ", ans);
        }
        printf("\n");
    }
    return 0;
}