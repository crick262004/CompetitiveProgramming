# Probability DP problems.

 <span style="font-size: 31.0;">
     **Probability DP problems.
In probability DP problems, we usually use back transitions but they might seem like front transitions.(BASE CASE IS KINDA AT THE TOP)
Set the value of the DP states as exactly what is asked in the problem. (the thing that each DP cell is storing)
Base case is the state where you know the probability of the answer trivially(usually 1 or 0 is this trivial probability)
(EACH DP STATE CELL IS STORING THE PROB. OF THE FINAL ANWER, GIVEN THE CONDNS AS SPECIFIED BY THAT STATE CELL PARAMS)
Transitions are based on going from P(ans/A) -> SIGMA_OVER_ALL_Bi ([P(ans/A&B1) * P(B1)])
and usually another layer of max/min over the different choices we could have(The Bi’s come once we pick a choice)
THE DP STATES ARE LIKE EVENTS (OF PROBABILITY THEORY)
So events become states, and probabilites become transition edges. 
AND WE USE TOTAL PROBABILITY THEOREM.**

 </span>
 <span style="font-size: 33.0;">
     **Probability DP : 
dp[…..] = “ prob. of exactly whats asked in qn”
Now, if we combine this with using Form1, 
the transitions completely align with 
Total Probability Theorem.**
 </span>