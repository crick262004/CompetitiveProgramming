# Vivek’s Hash Functions:


 <span style="font-size: 26.0;">
     Permutation : 
assumed permutation was a number represented in x-base and then converted to its decimal value 
Thus, abcdefg —> [a + bx + cx^2 + dx^3 + … ]%M

 </span>
 <span style="font-size: 26.0;">
     Set : 
{a, b, c} -> [(a + K)^H + (b + K)^H + … ]%M;
 </span>

 <span style="font-size: 26.0;">
     XOR : 
{a, b, c} —> [(a + K)%M ^ (b +K)%M ^ …]

 </span>