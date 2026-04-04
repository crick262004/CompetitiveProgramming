# COUNT SET BITS


__builtin_popcountll(n)


int countSetBits(int n)
{
    int count = 0;
    while (n)
    {
        n = n & (n - 1);
        count++;
    }
    return count;
}


![16C7281E-F1EB-4450-AF06-F67B6EE8E42F](images/16C7281E-F1EB-4450-AF06-F67B6EE8E42F.png)
int countSetBitsUptoN(int n) {
        int count = 0;
        while (n > 0) {
            int x = log2(n);
            count += x << (x - 1);
            n -= 1 << x;
            count += n + 1;
        }
        return count;
}