# GCD, LCM : KEEP


 <span style="font-size: 21.0;">
     int gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}
// iterative version:
int gcd (int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

 </span>
 <span style="font-size: 21.0;">
     int lcm(int a, int b)
{
    return ((a / gcd(a, b)) * b);
}

 </span>
 <span style="font-size: 28.0;">
     # **LCM of multiple values**

 </span> <span style="font-size: 21.0;">
        long long lcm_multiple(const std::vector<int>& numbers) {
       if (numbers.empty()) return 1; 
 </span> <span style="font-size: 21.0;">
     *// LCM of an empty set is 1*
 </span> <span style="font-size: 21.0;">
     
       return std::accumulate(numbers.begin() + 1, numbers.end(), (long long)numbers[0], std::lcm<long long, long long>);
   }

 </span>![A7324EDC-1DAB-47E0-9A3F-92977EADBE88](images/A7324EDC-1DAB-47E0-9A3F-92977EADBE88.png)
![802749AF-4C9D-4C8E-81D8-C5D671AA9E8A](images/802749AF-4C9D-4C8E-81D8-C5D671AA9E8A.png)
![CBA0ADAE-5C84-46B3-B176-5270E5526788](images/CBA0ADAE-5C84-46B3-B176-5270E5526788.png)
