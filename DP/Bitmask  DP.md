# Bitmask  DP

How to detect DP Bitmask: one of the DP state parameters is a subset, we need to analyze each subset as a state dimension, and `n` is small.
The problem usually requires considering all subsets/orderings of a 10-20 sized set.
One parameter of the state is the mask.

Such a common observation: a problem requires exploring all orderings/permutations (hence, `n!`), and so we optimize it using `dp[subset][last]`, which brings it to `n * 2^n`.
 