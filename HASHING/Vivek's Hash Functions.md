# Vivek’s Hash Functions

 
Permutation : 
assumed permutation was a number represented in x-base and then converted to its decimal value 
Thus, abcdefg —> [a + bx + cx^2 + dx^3 + … ]%M

 
 
Set : 
{a, b, c} -> [(a + K)^H + (b + K)^H + … ]%M;
 

 
XOR : 
{a, b, c} —> [(a + K)%M ^ (b +K)%M ^ …]
