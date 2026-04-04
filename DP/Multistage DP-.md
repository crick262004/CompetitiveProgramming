# Multistage DP:

 <span style="font-size: 33.0;">
     Problem has a handful of distinct, disjoint, sequential modes/stages.
When problem has stages and 1-directional branching bw stages.
We keep the stage_cnt/ stage_index as a parameter of the dp
Thus,
 </span> <span style="font-size: 33.0;">
      **dp[index][stage] : arr[0…index] has been resolved, and we are at stage stage rn.**
 </span> <span style="font-size: 33.0;">
     
Example: create exactly K non-empty, disjoint subarrays s.t. sum of all is max
(2k+1 disjoint stages)

I think Buy&Sell stocks is also Stage DP
 </span>