# power of 2



bool isPowerOfTwo(unsigned int n) {
    return n && !(n & (n - 1));
}

bool isPowerOfTwo(int n) {
    if(n<1)
        return false;
    return ((n & (n-1) ) == 0);
}


bool isDivisibleByPowerOf2(int n, int k) {
    int powerOf2 = 1 << k;
    return (n & (powerOf2 - 1)) == 0;
}