# Smallest Prime Factor technique


 <span style="font-size: 18.0;">
     vector<int> findPrimeFactors(int n) {
    vector<int> spf(n+1, 0); // smallest prime factor of i = spf[i]
    for(int i = 1; i<= n; i++)
    {
        spf[i] = i;
    }
    for(int i = 2; i*i <=n; i++)
    {
        if(spf[i] == i)
        {
            for(int j = i*i; j<=n; j += i)
            {
                if(spf[j] == j)
                    spf[j] = i;
            }
        }
    }
    int pf = n;
    vector<int> ans;
    while(pf != 1)
    {
        ans.push_back(spf[pf]);
        pf = pf / spf[pf];
    }
    return ans;
}
 </span>