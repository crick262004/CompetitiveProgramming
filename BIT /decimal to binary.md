# decimal to binary

# Can also be done using bitsets

![526F04BD-4FDC-4F64-B4F7-2914D031F2F5](images/526F04BD-4FDC-4F64-B4F7-2914D031F2F5.png)
![9CCA6239-C94B-4BCF-BB86-67A80F14932B](images/9CCA6239-C94B-4BCF-BB86-67A80F14932B.png)
string decToBinary(int n) {
    
    string bin = "";
    while (n > 0) {
        // checking the mod 
		int bit = n%2;
      	bin.push_back('0' + bit);
        n /= 2;
    }
    
    // reverse the string 
	reverse(bin.begin(), bin.end());
    return bin;
}