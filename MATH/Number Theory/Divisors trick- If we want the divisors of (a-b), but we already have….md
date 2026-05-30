# Divisors trick: If we want the divisors of (a*b), but we already have…

 <span style="font-size: 33.0;">
     **Divisors trick:
If we want the divisors of (a*b), but we already have the values a and b. Then instead of doing findDivisors(a*b) we can just do fD(a) and fD(b) separately, and then doing a O(n^2) loop over each divisors of a * divisors of b.
This is because fD(…) is O(rootn) but the actual divisors that come out are much much less.
Hence, whenever we have a factor-pair of a number, its more efficient to caluculate all divisors this way.**
 </span>