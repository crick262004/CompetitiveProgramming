# Stress Testing:

![0F3204A5-A6AB-409D-9D1F-8286E20EBECB](images/0F3204A5-A6AB-409D-9D1F-8286E20EBECB.png)

**`C.cpp` is the actual solution**
**`copy_checker.cpp` is where I copy `C.cpp`, then edit the real solve function, and also create the checker or brute force generator.**
**`generator.cpp` is just to create test cases, and then run:**
```bash
g++ ./generator.cpp && ./a.out < output.txt > ./input.txt
```
**And then run the simple build command over `copy_checker.cpp`**

1. **Slow Brute Force / Checker**
2. **Generator ( small tc )**

**If the generator doesn’t catch the bug ( cos we use small bounds, for high prob of edge case examples)**
1. **Check overflow**
2. **Undefined Behaviour**
3. **Max Test**

**Runtime Error, Use Flags (out-of-bounds):** 
```bash
g++ -std=c++17 -Wshadow -Wall -o a a.cpp -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG -g
```

**Check Time on Max Test:** 
```bash
g++ -O2 -std=c++17 -Wno-unused-result -Wshadow -Wall -o a a.cpp
```

*Also print the test case you pass, so that we can tell that a test case isn’t going into an infinite loop.*
