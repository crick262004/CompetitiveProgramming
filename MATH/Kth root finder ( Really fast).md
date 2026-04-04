# Kth root finder ( Really fast)



*// Safe power calculation to check if r^k > n*
*// Returns n + 1 if the result exceeds n (saturation)*
*inline* *ll* power_safe(*ll* base, int exp, *ll* limit) {
    unsigned __int128 res = 1;
    for (int i = 0; i < exp; i++) {
        res *= base;
        if (res > limit) return limit + 1;
    }
    return (*ll*)res;
}

*// Optimized kth-root finder: O(1) instead of O(log n)*
*inline* *ll* kth_root(*ll* n, int k) {
    if (k == 1) return n;
    *// For k=2, sqrtl is precise enough on most platforms, but we can stick to the generic logic*
    *// Estimate using floating point*
    *ll* r = round(pow(n, 1.0 / k));
    
    *// Correct the estimate*
    *// If (r+1)^k <= n, we underestimated*
    while (power_safe(r + 1, k, n) <= n) r++;
    *// If r^k > n, we overestimated*
    while (power_safe(r, k, n) > n) r--;
    
    return r;
}