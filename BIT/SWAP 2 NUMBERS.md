# SWAP 2 NUMBERS


pair<int, int> swap(int a, int b){
    a = a^b;
    b = a^b;
    a = a^b;
    return {a,b};
}