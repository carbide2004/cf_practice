#include <bits/stdc++.h>
#define ll long long

int s[100], ans;

void solve(int x) {
    for (int i = 0; i < 100; i++) {
        if (x % 2 == 0)
            s[i]++;
        else 
            ans++;
        x >>= 1;
    }
}

int main() {
    int t, n, x;
    ll  k;
    scanf("%d", &t);
    while (t--) {
        for (int i = 0; i < 100; i++)
            s[i] = 0;
        ans = 0;
        scanf("%d%lld", &n, &k);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &x);
            solve(x);
        }
        for (int i = 0; i < 100; i++) {
            if (k > 1LL * s[i] * (1LL << i)) {
                k -= 1LL * s[i] * (1LL << i);
                ans += s[i];
            }
            else {
                ans += k / (1LL << i);
                break;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}