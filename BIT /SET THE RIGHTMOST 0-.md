# SET THE RIGHTMOST 0:


int setBit(int n) {
    // int temp = ~n;
    // return (n | (temp ^ (temp & temp-1)));
    // return ~((~n) & ((~n) -1 ));
    
    return (n | (n+1));
}
