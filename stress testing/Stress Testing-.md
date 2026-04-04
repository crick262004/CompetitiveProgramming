# Stress Testing:

![0F3204A5-A6AB-409D-9D1F-8286E20EBECB](images/0F3204A5-A6AB-409D-9D1F-8286E20EBECB.png)
 <span style="font-size: 23.0;">
     **C.cpp is the actual solution
copy_checker is where I copy C.cpp, then edit the real solve function, and also create the checker or brute force
generator.cpp is just to create test cases, and then run:
g++ ./generator.cpp && ./a.out < output.txt > ./input.txt
And then run the simple build command over copy_checker.cpp**


 </span>
 <span style="font-size: 44.0;text-align: left;">
     1. **Slow Brute Force / Checker**

 </span> <span style="font-size: 44.0;text-align: left;">
     2. **Generator ( small tc )**
 </span> <span style="font-size: 30.0;">
     **If the generator doesn’t catch the bug ( cos we use small bounds, for high prob of edge case examples)**

 </span> <span style="font-size: 30.0;">
     	1. **Check overflow**

 </span> <span style="font-size: 30.0;">
     	2. **Undefined Behaviour**

 </span> <span style="font-size: 30.0;">
     	3. **Max Test**
 </span> <span style="font-size: 30.0;">
     
**Runtime Error, Use Flags (out-of-bounds):** 

 </span> <span style="font-size: 22.0;">
     g++ -std=c++17 -Wshadow -Wall -o a a.cpp -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG -g
 </span> <span style="font-size: 30.0;">
     

**Check Time on Max Test:** 

 </span> <span style="font-size: 22.0;">
     g++ -O2 -std=c++17 -Wno-unused-result -Wshadow -Wall -o a a.cpp
 </span>

# also print the test case you pass, so that we can tell that a test case ins’t going into infinite loop
