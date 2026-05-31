# Multistage DP:

Problem has a handful of distinct, disjoint, sequential modes or stages.
When a problem has stages and one-directional branching between stages, we keep `stage_cnt` or `stage_index` as a DP parameter.
Thus,

`dp[index][stage]`: `arr[0…index]` has been resolved, and we are at stage `stage` right now.

Example: create exactly K non-empty, disjoint subarrays s.t. sum of all is max
(2k+1 disjoint stages)

I think Buy&Sell stocks is also Stage DP
 