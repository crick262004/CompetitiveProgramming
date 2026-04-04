# Z-Function

# ![662D07C8-7A56-4C41-92DC-6A8B6E710B6B](images/662D07C8-7A56-4C41-92DC-6A8B6E710B6B.png)

 <span style="font-family: .AppleSystemUIFont; font-size: 13.0;">
     # vector<int> z_function(string s) {

 </span>    int n = s.size();
    vector<int> z(n, 0);
    int l = 0, r = 0;
    for(int i = 1; i < n; i++) {
        if(i < r) {
            z[i] = min(r - i, z[i - l]);
        }
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if(i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}



![BEA55D01-44DB-48B1-BC18-259B661B99E6](images/BEA55D01-44DB-48B1-BC18-259B661B99E6.png)
 <span style="font-size: 32.0;">
     Used a lot when problems mention suffixes and prefixes.

 </span> <span style="font-size: 32.0;">
     e.g. 

 </span> <span style="font-size: 18.0;">
     [https://cses.fi/problemset/task/1732](https://cses.fi/problemset/task/1732)
 </span>
 <span style="font-size: 18.0;">
     [https://codeforces.com/problemset/problem/126/B](https://codeforces.com/problemset/problem/126/B)
 </span>
 <span style="font-size: 18.0;">
     [https://codeforces.com/problemset/problem/432/D](https://codeforces.com/problemset/problem/432/D)
 </span>
![F6B3C50F-AE69-4CE3-B675-CCBC00D91294](images/F6B3C50F-AE69-4CE3-B675-CCBC00D91294.png)

![170F208A-BC74-47D5-9488-3606CC7DDE6D](images/170F208A-BC74-47D5-9488-3606CC7DDE6D.png)

![64F7CAD7-03AB-4C4D-8865-F6DB6DF15956](images/64F7CAD7-03AB-4C4D-8865-F6DB6DF15956.png)

