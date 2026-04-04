# Playlist:

 <span style="font-size: 28.0;">
     define each state with a label of W or L
DP / Recursion / Induction type thinking. 
Think about base case, and then move up from there, then see pattern.
 </span>
![6E34865A-1284-4AB9-8C31-AD90FEF538C2](images/6E34865A-1284-4AB9-8C31-AD90FEF538C2.png)

 <span style="font-size: 29.0;">
     # **Nim Game**

 </span>

 <span style="font-size: 31.0;">
     # **Sprague Grundy Numbers & Mex**

 </span> <span style="font-size: 24.0;">
     Mex is just a mathematical workaround to do the : Need one Losing state to go to, to call this winning state.
(and if no losing state to go to, then this is losing state)

It could’ve been compressed to 0 and 1? No, because of Sprague - Grundy Theorem

 </span>
 <span style="font-size: 24.0;">
     So somehow, the Grundy numbers store some cyclicity information.

 </span>
 <span style="font-size: 24.0;">
     Proof behind Sprague - Grundy:
For Each subgame, the Grundy Number can always decreased to any value less than it ( Because it was the mex of previous states)
This matches perfectly with Nim Game.
2 other cases: What if we increase the Grundy Number of a sub-game? Then the other guy can always come back to the original Grundy Number in one move, hence resetting the game.
And if Grundy Number is 0, then also the same thing can happen. Hence, effectively no change, if other guy wants.
So, if XOR = 0, other guy can always mantain XOR = 0.
 </span>
![830CB4BD-9C7A-45AE-8F44-7E7976BBF5D8](images/830CB4BD-9C7A-45AE-8F44-7E7976BBF5D8.png)

