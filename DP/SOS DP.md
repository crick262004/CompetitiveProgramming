# SOS DP

[https://codeforces.com/blog/entry/149201](https://codeforces.com/blog/entry/149201)
![5FB8D33C-8BD4-4242-AA16-C5A9BC9D39D9](images/5FB8D33C-8BD4-4242-AA16-C5A9BC9D39D9.png)
![EA5B1EB2-6699-4325-B055-BE4C5170E1ED](images/EA5B1EB2-6699-4325-B055-BE4C5170E1ED.png)
for (int mask = 0; mask < (1<<n); mask++) {
    for (int sub = mask; sub; sub = (sub-1) & mask) {
        F[mask] += f[sub];
    }
}

# ![3B462F1B-7FE7-4B5B-A91D-69BEA457DEDF](images/3B462F1B-7FE7-4B5B-A91D-69BEA457DEDF.png)
for (int i = 0; i < n; i++) {
    for (int mask = 0; mask < (1<<n); mask++) {
        if (mask & (1<<i)) {
            F[mask] += F[mask ^ (1<<i)];
        }
    }
}
![6B00D5B6-2EB8-4845-8B71-6E71B719A18C](images/6B00D5B6-2EB8-4845-8B71-6E71B719A18C.png)



