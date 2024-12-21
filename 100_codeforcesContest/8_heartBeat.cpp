#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n + 1), b(n + 1), c(n);
    
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
    }
    
    for (int i = 1; i <= n; ++i) {
        std::cin >> b[i];
    }
    
    for (int i = 0; i < n; ++i) {
        std::cin >> c[i];
    }

    std::vector<int> factorial(n + 1, 1);
    for (int i = 2; i <= n; ++i) {
        factorial[i] = (1LL * factorial[i-1] * i) % MOD;
    }

    auto mod_mul = [](int x, int y) -> int {
        return (1LL * x * y) % MOD;
    };
    
    for (int k = 1; k <= n; ++k) {
        int result = 0;
        for (int x = 1; x <= k; ++x) {
            for (int y = 1; y <= k; ++y) {
                if (x + y - 1 > k) continue;
                int z = k - x - y + 1;
                int cost = mod_mul(mod_mul(a[x], b[y]), c[z]);
                int combinations = mod_mul(mod_mul(factorial[k - 1], factorial[x - 1]), mod_mul(factorial[y - 1], factorial[z]));
                result = (result + mod_mul(cost, combinations)) % MOD;
            }
        }
        std::cout << result << (k == n ? '\n' : ' ');
    }

    return 0;
}
