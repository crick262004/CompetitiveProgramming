// Roman to Integer : I guess keep


[Roman to Integer](https://leetcode.com/problems/roman-to-integer/)

 : I guess keep


int romanToInt(string s) {
    /*
    if next value is greater, then:
   add the 4,9,40,90,400, etc. and skip 1 value
    otherwise:
   simply add the current value
    */
    int sum = 0;
    unordered_map  r;
    r['I'] = 1;
    r['V'] = 5;
    r['X'] = 10;
    r['L'] = 50;
    r['C'] = 100;
    r['D'] = 500;
    r['M'] = 1000;

    for(int i = 0; i< s.length(); i++)
    {
   char ch = s[i];
   if(i != s.length() -1 && r[ch] < r[s[i+1]])
       sum -= r[ch];
   else
       sum += r[ch];
    }
    return sum;
}