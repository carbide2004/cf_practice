#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn = 2e5 + 10;
const ll inf = 2e15;
ll p[maxn], d[maxn];
int tr[maxn][2], vis[maxn][2], f[maxn][2];
map<ll, vector<int> > mp1, mp2;
// tr[i][0/1]: 在i转向，且转向后朝左0右1，的下一个会转向的点

int search(int dir, ll pos) {
    if (vis[pos][dir]) return f[pos][dir] = -1;
    vis[pos][dir] = 1;
    if (tr[pos][dir ^ 1] == 0) {
        return f[pos][dir] = 1;
    } 
    if (f[tr[pos][dir ^ 1]][dir ^ 1]) return f[pos][dir] = f[tr[pos][dir ^ 1]][dir ^ 1];
    return f[pos][dir] = search(dir ^ 1, tr[pos][dir ^ 1]);
}

int main() {
    int t, n, q;
    ll k, x;
    scanf("%d", &t);
    while (t--) {
        mp1.clear();
        mp2.clear();
        memset(tr, 0, sizeof(tr));
        memset(f, 0, sizeof(f));
        memset(vis, 0 ,sizeof(vis));
        scanf("%d%lld", &n, &k);
        for (int i = 1; i <= n; i++) scanf("%lld", &p[i]);
        for (int i = 1; i <= n; i++) scanf("%lld", &d[i]);
        for (int i = 1; i <= n; i++) {
            mp1[(p[i] + d[i]) % k].push_back(i);
            mp2[(p[i] - d[i] + k) % k].push_back(i);
        }
        for (int i = 1; i <= n; i++) {
            // for (int j = i - 1; j >= 1; j--)
            //     if ((p[i] - p[j] - d[j] + d[i] + k)) {
            //         tr[i][0] = j;
            //         break;
            //     }
            // for (int j = i + 1; j <= n; j++)
            //     if ((p[j] - p[i] - d[j] + d[i] + k) % k == 0) {
            //         tr[i][1] = j;
            //         break;
            //     }
            auto it = mp1.find((p[i] + d[i]) % k);
            int res = 0;
            if (it != mp1.end()) {
                // for (auto pt = it->second.begin(); pt != it->second.end(); pt++) {
                //     if (*pt < i && *pt > res) res = *pt;
                // }
                // tr[i][0] = res;
                auto pt = lower_bound(it->second.begin(), it->second.end(), i);
                if (pt != it->second.begin()) {
                    pt--;
                    tr[i][0] = *pt;
                }
            }
            
            it = mp2.find((p[i] - d[i] + k) % k);
            res = n;
            if (it != mp2.end()) {
                auto pt = upper_bound(it->second.begin(), it->second.end(), i);
                if (pt != it->second.end()) {
                    tr[i][1] = *pt;
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            // memset(vis, 0, sizeof(vis));
            if (!f[i][0]) f[i][0] = search(0, i);
            if (!f[i][1]) f[i][1] = search(1, i);
        }
        scanf("%d", &q);
        for (int i = 1; i <= q; i++) {
            scanf("%lld", &x);
            auto it = mp2.find(x % k);
            if (it == mp2.end()) {
                printf("YES\n");
                continue;
            }
            vector<int> vec = it->second;
            int l = 0, r = vec.size() - 1, mid, ans = -1;
            while (l <= r) {
                mid = (l + r) >> 1;
                if (p[vec[mid]] >= x) {
                    ans = mid;
                    r = mid - 1;
                }
                else {
                    l = mid + 1;
                }
            }
            if (ans == -1) {
                printf("YES\n");
                continue;
            }
            if (f[vec[ans]][1] == -1) {
                printf("NO\n");
            }
            else {
                printf("YES\n");
            }
        }
    }
    return 0;
}