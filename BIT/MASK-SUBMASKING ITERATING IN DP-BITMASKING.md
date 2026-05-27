# MASK-SUBMASKING ITERATING IN DP-BITMASKING

## For each mask, we need submasks that are 1 bit off.
**(2^n * 30)**
```cpp
for(int m = 0; m<(1<<n); m++){
    for(int psn = 0; psn < n; psn++){
        if(((m>>psn)&1)){
            int s = (m ^ (1<<psn));
            // work back transition [ m -> s]
        }
    }
}
```

![917B87F5-125F-44EF-92C8-652B0DB85939](images/917B87F5-125F-44EF-92C8-652B0DB85939.png)

## For each mask, we need all submasks that could be built from set bits of mask.
**(3^n)**

![B045DE3C-8AD5-4ECF-9117-DD4C77AC49C5](images/B045DE3C-8AD5-4ECF-9117-DD4C77AC49C5.png)
![5D3F3A2F-E472-43F4-A98C-00D2978F7B4E](images/5D3F3A2F-E472-43F4-A98C-00D2978F7B4E.png)
```cpp
for(int m = 0; m<(1<<n); m++){
    for(int s = m; ;s = ((s-1)&m)){
        // work back transition [ m -> s]
        if(s == 0)
            break;
    }
}
```
![F5842D0E-6426-47F8-8E20-34E6E678C4EC](images/F5842D0E-6426-47F8-8E20-34E6E678C4EC.png)

## This same (3^n) idea, but now doing front transitions/ push dp:
```cpp
for(int mask=0; mask<N; ++mask){
    int rem = ((N-1) ^ mask);
    // iterate through non-empty submasks of rem
    for(int sub = rem; sub; sub = (sub-1) & rem){
        // front transition from dp[mask] to dp[nmask], where sub is the extra part that adds to mask, to make nmask
        int nmask = mask | sub;
    }
}
```
