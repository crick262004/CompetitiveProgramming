# Primes

```cpp
vector<int> spf(N+1, 0); // smallest prime factor of i = spf[i]

void pf_sieve(){ // call in precomputation, total TC is O(Nlog(log(N)))
    for(int i = 1; i<= N; i++){ // O(N)
        spf[i] = i;
    }

    for (int i = 2; i*i <= N; i++) { // O(N*log(log(N))) making the sieve
        if (spf[i] == i) { // THUS spf[i] == i
            for (int j = i * i; j <= N; j += i){
                if(spf[j] == j){ // THUS is_prime[j] is true, and we need to change it
                    spf[j] = i;
                }
            }
        }
    }
}
```

Sieve : O( N * log(log(N)) )

(TO PRECOMPUTE 
<u>IF VALUE IS PRIME</u>
FROM 1 TO N,
<u>TO STORE ALL THE PRIMES</u>
FROM 1 TO N,

<u>CALCULATING SPF TABLE</u>
FROM 1 TO N)

```cpp
vector<bool> is_prime(N+1, true);
vector<int> primes;
vector<int> spf(N+1, 0); // smallest prime factor of i = spf[i]

void pf_sieve(){ // call in precomputation, total TC is O(Nlog(log(N)))
    for(int i = 1; i<= N; i++){ // O(N)
        spf[i] = i;
    }

    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i*i <= N; i++) { // O(N*log(log(N))) making the sieve
        if (is_prime[i]) { // THUS spf[i] == i
            for (int j = i * i; j <= N; j += i){
                if(spf[j] == j){ // THUS is_prime[j] is true, and we need to change it
                    spf[j] = i;
                    is_prime[j] = false;
                }
            }
        }
    }

    for(int i = 0; i<=N; i++){ // O(n)
        if(is_prime[i]){
            primes.push_back(i);
        }
    }
}
```

**isPrime : (If you didn’t apply sieve)**

```cpp
bool isPrime(int x) { // O(root(n))
    for (int d = 2; d * d <= x; d++) {
        if (x % d == 0)
            return false;
    }
    return x >= 2;
}
```

**Prime Factorisation:**

[https://cp-algorithms.com/algebra/factorization.html](https://cp-algorithms.com/algebra/factorization.html)

**1.WITHOUT SIEVE:**

```cpp
vector<long long> trial_division1(long long n) { // O(root(n))
    vector<long long> factorization;
    for (long long d = 2; d * d <= n; d++) {
        while (n % d == 0) {
            factorization.push_back(d);
            n /= d;
        }
    }
    if (n > 1)
        factorization.push_back(n);
    return factorization;
}
```

**2.WITH SIEVE(spf table):**

```cpp
vector<pair<int,int>> findPrimeFactors(int n) { // O(log(n))
    vector<pair<int, int>> prime_factors;
    
    while (n > 1) {
        int p = spf[n];
        int count = 0;
        while (n % p == 0) { 
            n /= p;
            count++;
        }
        prime_factors.push_back({p, count});
    }
    return prime_factors;
}

vector<int> findPrimeFactors(int n) { // O(log(n))
    int pf = n;
    vector<int> ans;
    while(pf != 1){
        ans.push_back(spf[pf]);
        pf = pf / spf[pf];
    }
    return ans;
}
```
