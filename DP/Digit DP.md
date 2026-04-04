# Digit DP


#include<bits/stdc++.h>
using namespace std;

typedef long long *ll*;

*ll* dp[20][10][2][2];

*ll* mem(*string* s, *ll* cur, *ll* last, *ll* leading_zero, *ll* tight){
    *// cout << "yes" << endl;*
    if(cur == 0){
        return 1;
    }
    if(dp[cur][last][leading_zero][tight] != -1)
        return dp[cur][last][leading_zero][tight];
    
    *ll* limit = 0;
    if(tight == 1){
        limit = s[s.size() - cur] - 48;
    } else{
        limit = 9;
    }
    *ll* countNumbers = 0;
    for(int d = 0; d<=limit; d++){
        if( (d == last) && (leading_zero==0) ){
            continue;
        }
        *ll* newlead = ( (leading_zero == 1 && d == 0) ? 1 : 0);
        *ll* newtight = (tight == 1 && d == limit)?1 : 0;
        countNumbers += mem(s, cur - 1,d,newlead,newtight);
    }
    return dp[cur][last][leading_zero][tight] = countNumbers;
}
int main(){
    *ll* a, b; cin >> a >> b;
    *ll* count1 = 0, count2 = 0;

    memset(dp, -1, sizeof(dp));
    
    if(a>0)
    {
        *string* s1 = to_string(a-1);
        count1 = mem(s1, s1.size(), -1, 1, 1);
    }
    memset(dp, -1, sizeof(dp));
    *string* s2 = to_string(b);
    count2 = mem(s2, s2.size(), -1, 1, 1);

    *// cout << count1 << " " << count2 << endl;*
    cout << count2 - count1 << endl;

}
