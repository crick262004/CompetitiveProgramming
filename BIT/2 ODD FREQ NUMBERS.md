# 2 ODD FREQ NUMBERS


vector<int> singleNumber(vector<int>& a) {
    int n = a.size();
    long long xorr = 0;
    for(int i = 0;i <n; i++){
        xorr = xorr ^ a[i];
    }
    int filter = (xorr & (~(xorr-1)));
    int f1 = 0;
    int f2 = 0;
    for(int i = 0; i<n; i++){
        if(filter & a[i])
            f1 = f1 ^ a[i];
        else
            f2 = f2 ^ a[i];
    }
    return {f1, f2};
}
