#include <iostream>
#include <vector>
#include <emscripten/emscripten.h>

extern "C" {
    // The "Forge" challenge: Calculate primes up to N using Sieve of Eratosthenes
    EMSCRIPTEN_KEEPALIVE
    int run_challenge(int n) {
        int count = 0;
        std::vector<bool> is_prime(n + 1, true);
        is_prime[0] = is_prime[1] = false;
        for (int p = 2; p * p <= n; p++) {
            if (is_prime[p]) {
                for (int i = p * p; i <= n; i += p)
                    is_prime[i] = false;
            }
        }
        for (int p = 2; p <= n; p++) {
            if (is_prime[p]) count++;
        }
        return count;
    }
}
