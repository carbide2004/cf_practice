#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    int a, b, c, d;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d%d%d", &a, &b, &c, &d);
        int x = min(a, c), y = min(b, d);
        if (x >= y) {
            printf("Gellyfish\n");
        }
        else {
            printf("Flower\n");
        }
    }
    return 0;
}