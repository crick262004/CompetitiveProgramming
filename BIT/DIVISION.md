# DIVISION


int divide(int dividend, int divisor) {
    // the O(Log(N)) solution.
    if(dividend == divisor)
        return 1;
    if(dividend == 0)
        return 0;
    int sign = 1;
    if(dividend > 0 && divisor < 0 || dividend < 0 && divisor > 0)
        sign = -1;
    if(divisor == 1 || divisor == -1)
    {
        if(dividend == INT_MIN)
            return sign == 1? INT_MAX : INT_MIN;
        return abs(dividend) * sign;
    }

    // done with edge cases.

    long n = abs((long)dividend);
    long d = abs((long)divisor);
    long ans = 0;

    // MAIN STUFF.
    while(n>=d)
    {
        int cnt = 0;
        while(n >= d<<(cnt+1) )
            cnt++;
        ans += (1<<cnt);
        n = n - (d<<cnt);
        // we basically leveraged the fact that 
        // multiplication with powers of 2 is super easy using bit shifts.
    }
    return sign * ans;
}
