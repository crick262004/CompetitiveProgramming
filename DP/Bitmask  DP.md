# Bitmask  DP


 <span style="font-size: 31.0;">
     **How to detect DP Bitmask : One of the  DP states params are subsets( we need to analyse each subset as 1 of the parameters of the state) 
AND n is small.
problem always involves needing to consider all subsets/orderings of 10-20 sized set.
One param of the state is the mask**

 </span>
 <span style="font-size: 33.0;">
     **Such a comon observation : A problem requires for us to explore all orderings/permutations (hence, n!) and so, we optimise it using dp[subset][last] which brings it to n*(2^n)**
 </span>