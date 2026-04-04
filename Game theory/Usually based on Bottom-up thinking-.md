# Usually based on Bottom-up thinking.

# Think of edge / base case where we can deduce verdict(W/L) trivially ( W/L is wrt current player) 
# Now build up from there, thinking about 1 step away from determined case.(and if it possible to force the other player into that state…) 
# And then recursively 1 step away from new determined cases and so on…


# Bottom-up thinking. 
# edge / base case
# 1 step away


 <span style="font-size: 32.0;">
     IF ANY POSSIBLE TRANSITION TO A LOSING STATE, THIS IS A WINNING STATE. ELSE THIS IS A LOSING STATE.
 </span>