# Probability DP problems.

Probability DP problems:
In probability DP problems, we usually use back transitions even though they may look like front transitions. The base case is often near the top.
Set the value of the DP states to exactly what is asked in the problem, since each DP cell stores that probability directly.
The base case is the state where the answer is trivially known, usually `1` or `0`.
Each DP state stores the probability of the final answer given the conditions specified by that state.
Transitions are based on `P(ans/A) -> sum over Bi [P(ans/A&B1) * P(B1)]`, often with an extra max/min over choices.
The DP states are like events in probability theory: events become states, and probabilities become transition edges.
We use the total probability theorem.

Probability DP:
`dp[...] = probability of exactly what's asked in the question`.
With that formulation, the transitions align cleanly with the total probability theorem.
 