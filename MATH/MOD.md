# MOD


void modadd(int &a , int b) {a=((a%MOD)+(b%MOD))%MOD;}
void modsub(int &a , int b) {a=((a%MOD)-(b%MOD)+MOD)%MOD;}
void modmul(int &a , int b) {a=((a%MOD)*(b%MOD))%MOD;}


int binpow(int a, int b, int mod)
{
    int res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res % mod;
}

int inversemod(int a, int mod)
{
    return binpow(a, mod - 2, mod);
}

int divmod(int a, int b, int c)
{
    return ((a % c) * inversemod(b, c)) % c;
}

![E782F8D3-9B5C-44CB-BD37-7A6EE469D305](images/E782F8D3-9B5C-44CB-BD37-7A6EE469D305.png)

int factmod(int n, int p) {
    vector<int> fa(n+1);
    fa[0] = 1;
    for (int i = 1; i <=n; i++)
        fa[i] = fa[i-1] * i % p;

    return fa[n];
}

int factmod(int n, int p) {
    vector<int> f(p);
    f[0] = 1;
    for (int i = 1; i < p; i++)
        f[i] = f[i-1] * i % p;

    int res = 1;
    while (n > 1) {
        if ((n/p) % 2)
            res = p - res;
        res = res * f[n%p] % p;
        n /= p;
    }
    return res;
}

![57FE1818-08C5-492B-BB32-872E9B5ECA6E](images/57FE1818-08C5-492B-BB32-872E9B5ECA6E.png)
![480AF871-150E-41BF-A1DA-930B42FDBBF1](images/480AF871-150E-41BF-A1DA-930B42FDBBF1.png)
