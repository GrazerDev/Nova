#include <iostream>
#include <vector>
#include <emscripten/emscripten.h>

extern "C" {

// This is the function people will try to optimize.
// The goal: Find how many prime numbers exist up to 'n' as fast as possible.
EMSCRIPTEN_KEEPALIVE
int run_challenge(int n) {
    if (n < 2) return 0;

    // Standard Sieve of Eratosthenes
    std::vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;

    for (int p = 2; p * p <= n; p++) {
        if (is_prime[p]) {
            for (int i = p * p; i <= n; i += p)
                is_prime[i] = false;
        }
    }

    int count = 0;
    for (int p = 2; p <= n; p++) {
        if (is_prime[p]) count++;
    }

    return count;
}

}
