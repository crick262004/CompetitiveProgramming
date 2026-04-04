# String to Integer (atoi) : doesn’t stoi or stoll do this?

 <span style="font-size: 26.0;">
     **[String to Integer (atoi)](https://leetcode.com/problems/string-to-integer-atoi/)**
 </span> <span style="font-size: 26.0;">
      **: doesn’t stoi or stoll do this?**

 </span>
int myAtoi(string s) {
    int n = s.length();
    int i = 0;
    int ans = 0;
    bool neg = false;
    
    // whitespaces
    while(i < n && s[i] == ' ')
        i++;

    // sign
    if(s[i] == '-')
    {
        neg = true;
        i++;
    }
    else if(s[i] == '+' )
        i++;

    while(i < n)
    {
        if( s[i] <'0' || s[i] > '9' )
            break;
        int dig = s[i] - '0';
        if(!neg)
        {
            if((double)ans*10 + dig >= (double)INT_MAX) return INT_MAX;
        }
        else
        {
            if((double)ans*10 + dig > (double)INT_MAX) return INT_MIN;
        }
        ans = ans * 10 + dig;
        i++;
    }
    if(neg) 
        return -1 * ans;
    else
        return ans;
}
