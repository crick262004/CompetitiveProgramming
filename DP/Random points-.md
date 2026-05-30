# Random points:

![1E713AC6-DD25-4648-BDDC-63925BB7A9DD](images/1E713AC6-DD25-4648-BDDC-63925BB7A9DD.png)


 <span style="font-size: 33.0;">
     # **In DP, the state represents all that really matters ( but also just enough that matters ) (Thus, compressed representation of all that matters, and only of what that actually matters)**

 </span> <span style="font-size: 33.0;">
     
**Problem can be modeled into something related to subsets : 
TAKE / NOT_TAKE DP!!!!!!!!!!!!!!!!!!!!!!!!!**

 </span> <span style="font-size: 32.0;">
     
VERY OFTEN WE PUT THE “K OPERATIONS” AS A PARAMETER IN THE DP STATE.


 </span> <span style="font-size: 34.0;">
     I thought dp is not possible in such scenarios where there are overlapping intervals. But it is. I think it's because every position is from 0 to n, and not till 1e9 or something.

 </span>![2D301E09-740B-4AE4-8B78-15E4A992B660](images/2D301E09-740B-4AE4-8B78-15E4A992B660.png)
![C476FF92-9FEF-4962-B9C6-3FCAF5213ACC](images/C476FF92-9FEF-4962-B9C6-3FCAF5213ACC.png)



 <span style="font-size: 33.0;">
     **Math / Divisors based:
Sometimes when iterating over all numbers, and for each number: every multiple
you don’t need to do actually every multiple, just do (1 prime) step up.
Good example:** 

 </span> <span style="font-size: 33.0;">
     **[https://codeforces.com/contest/1614/problem/D2](https://codeforces.com/contest/1614/problem/D2)**
 </span> <span style="font-size: 33.0;">
     
**D1 used going over all multiples, but no need.**
 </span>
![C8E6EC94-03FE-475F-B1BB-BF120A1BB2D7](images/C8E6EC94-03FE-475F-B1BB-BF120A1BB2D7.png)
