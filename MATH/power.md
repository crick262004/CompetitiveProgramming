# power


double myPow(double x, int n) {
    long long nn = n;
    if(nn<0) nn *=-1;
    double ans = 1;
    while(nn)
    {
        if(nn %2 == 1)
        {
            ans *=x;
            nn --;
        }
        else
        {
            x = x*x;
            nn /=2;
        }
    }
    if(n<0)
        return ( double(1) / ans );
    else
        return ans;
}