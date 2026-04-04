# Count Substrings with K Distinct : Put it in common Idea of SW, not…

 <span style="font-size: 22.0;">
     **Count Substrings with K Distinct : Put it in common Idea of SW, not here**

 </span>
 <span style="font-size: 17.0;">
     int util(string s, int k){
    if(k<= 0)
        return 0;
    int l = 0;
    int r = 0;
    int cnt = 0;
    map<char, int> mp;
    int n = s.length();
    for(int r = 0; r<n; r++){
        char ch = s[r];
        mp[ch]++;
        while(l<=r && mp.size() > k){
            char c = s[l];
            if(mp[c] == 1)
                mp.erase(c);
            else
                mp[c]--;
            l++;
        }
        cnt += (r-l+1);
    }
    return cnt;
}
int countSubstr(string& s, int k) {
    // code here.
    return util(s, k) - util(s, k-1);
}
 </span>