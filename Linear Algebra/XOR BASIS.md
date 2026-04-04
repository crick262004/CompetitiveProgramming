# XOR BASIS

 <span style="font-size: 24.0;">
     CODE:

 </span> <span style="font-size: 15.0;">
     #include <bits/stdc++.h>
#define int long long
using namespace std;
int d = 20;
 </span> <span style="font-size: 15.0;">
      *// the bit-width of the numbers*
 </span> <span style="font-size: 15.0;">
     
vector<int> basis(d, 0);
 </span> <span style="font-size: 15.0;">
      *// basis[i] keeps the mask of the vector whose f value is i*
 </span> <span style="font-size: 15.0;">
     
int sz;
 </span> <span style="font-size: 15.0;">
      *// Current size of the basis*
 </span>
 <span style="font-size: 15.0;">
     *const*
 </span> <span style="font-size: 15.0;">
      int mod = 1e9 + 7;


 </span> <span style="font-size: 15.0;">
     **void insertVector(int mask) {
    for (int i = d-1; i >= 0; i--) {
        if ((mask & 1ll << i) == 0) continue;**
 </span> <span style="font-size: 15.0;">
      ***// continue if i != f(mask)***
 </span> <span style="font-size: 15.0;">
     

        **if (!basis[i]) {**
 </span> <span style="font-size: 15.0;">
      ***// If there is no basis vector with the i'th bit set, then insert this vector into the basis***
 </span> <span style="font-size: 15.0;">
     
            **basis[i] = mask;
            ++sz;
            return;
        }else{
            mask ^= basis[i];**
 </span> <span style="font-size: 15.0;">
      ***// Otherwise subtract the basis vector from this vector***
 </span> <span style="font-size: 15.0;">
     
        **}
    }
}**
 </span> <span style="font-size: 15.0;">
     

int kthlargest(int k){
 </span> <span style="font-size: 15.0;">
      *// the k'th hightest number from the Set S*
 </span> <span style="font-size: 15.0;">
     
    int mask = 0;
    int tot = (1ll<<sz);
    for(int i = d-1; i>=0; i--){
        if(basis[i]){
            int mid = tot / 2;
            int bit = ((mask>>i) & 1ll);
            if(k > mid && bit == 0){
                mask ^= basis[i];
            } else if(k <= mid && bit > 0){
                mask ^= basis[i];
            }

            if(k > mid){
                k -= mid;
            }
            tot /= 2;
        }
    }
    return mask;
}

bool poss(int x){ // or “is linearly dependent?”
    for(int i = d-1; i>=0; i--){
        if((x >> i)&1ll){
            if(basis[i]){
                x ^= basis[i];
            } else{
                return false;
            }
        }
    }
    return true;
}

int32_t main() {
    int n; cin >> n;
    vector<int> a(n); 
    for(int i = 0; i<n; i++) {
        cin >> a[i];

 </span> <span style="font-size: 15.0;">
             **insertVector(a[i]);**
 </span> <span style="font-size: 15.0;">
     
    }


 </span> <span style="font-size: 15.0;">
         **int distincts = (1ll << sz);**
 </span> <span style="font-size: 15.0;">
      ***// the number of distinct integers that can be represented using xor over any subset of the set of the given elements.***
 </span> <span style="font-size: 15.0;">
     

    **int maxSubsetXor = 0;**
 </span> <span style="font-size: 15.0;">
      ***// maximum possible xor of the elements of some subset of*** 
 </span> <span style="font-family: STIXTwoMath-Regular; font-size: 15.0;">
     𝑆
 </span> <span style="font-size: 15.0;">
     
    **for(int i = d-1; i>=0; i--){
        if( ( ((maxSubsetXor>>i)&1ll) == 0) && basis[i]){
            maxSubsetXor ^= basis[i];
        }
    }**
 </span> <span style="font-size: 15.0;">
     
    return 0;
}



 </span>
 <span style="font-size: 24.0;">
     THEORY:
 </span>
![F55B8625-62FB-4309-8F03-AABCD4E986DA](images/F55B8625-62FB-4309-8F03-AABCD4E986DA.png)

![83D475E6-FAA3-4999-8447-EECAF055D609](images/83D475E6-FAA3-4999-8447-EECAF055D609.png)
![EF09F448-B342-43E7-BE12-A90818DA3BAB](images/EF09F448-B342-43E7-BE12-A90818DA3BAB.png)
![C5DC1905-6066-437C-847B-41703F711366](images/C5DC1905-6066-437C-847B-41703F711366.png)
![87F61970-28D9-4C40-B990-CAA7456A20BD](images/87F61970-28D9-4C40-B990-CAA7456A20BD.png)
![BA44C623-797E-41FE-B010-AD8D62483DC2](images/BA44C623-797E-41FE-B010-AD8D62483DC2.png)
![A36BC517-B6F2-4EC5-BDD2-5FBD9CEB8673](images/A36BC517-B6F2-4EC5-BDD2-5FBD9CEB8673.png)
 <span style="font-size: 24.0;">
     [https://codeforces.com/blog/entry/68953](https://codeforces.com/blog/entry/68953)
 </span>
![8277C637-B743-4FD8-A07D-30112E6079DA](images/8277C637-B743-4FD8-A07D-30112E6079DA.png)
![3210E056-0E90-4734-BABF-BAD97656DD3D](images/3210E056-0E90-4734-BABF-BAD97656DD3D.png)
