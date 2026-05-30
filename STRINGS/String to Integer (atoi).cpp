// String to Integer (atoi) : doesn’t stoi or stoll do this?


[String to Integer (atoi)](https://leetcode.com/problems/string-to-integer-atoi/)

 : doesn’t stoi or stoll do this?


int myAtoi(string s) {
    int n = s.length();
    int i = 0;
    int ans = 0;
    bool neg = false; // whitespaces
    while(i  '9' )
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