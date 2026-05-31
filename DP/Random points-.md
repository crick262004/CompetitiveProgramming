# Random points:

![1E713AC6-DD25-4648-BDDC-63925BB7A9DD](images/1E713AC6-DD25-4648-BDDC-63925BB7A9DD.png)


In DP, the state represents all that really matters, but also just enough that matters. This is a compressed representation of everything relevant, and only of what is relevant.

Problem can be modeled into something related to subsets: take / not-take DP.

Very often we put the `K` operations as a parameter in the DP state.

I thought DP is not possible in such scenarios where there are overlapping intervals. But it is. I think it's because every position is from `0` to `n`, and not up to `1e9` or something.

![2D301E09-740B-4AE4-8B78-15E4A992B660](images/2D301E09-740B-4AE4-8B78-15E4A992B660.png)
![C476FF92-9FEF-4962-B9C6-3FCAF5213ACC](images/C476FF92-9FEF-4962-B9C6-3FCAF5213ACC.png)



Math / divisors based:
Sometimes when iterating over all numbers, and for each number, every multiple does not need to be processed explicitly. You can often step up by one prime factor move instead.
Good example:

[https://codeforces.com/contest/1614/problem/D2](https://codeforces.com/contest/1614/problem/D2)

D1 used going over all multiples, but that was not necessary.
 
![C8E6EC94-03FE-475F-B1BB-BF120A1BB2D7](images/C8E6EC94-03FE-475F-B1BB-BF120A1BB2D7.png)
