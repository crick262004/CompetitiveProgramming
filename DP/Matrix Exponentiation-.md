# Matrix Exponentiation:

 <span style="font-size: 43.0;">
     # **[https://www.youtube.com/watch?v=kQuCOFzWoa0](https://www.youtube.com/watch?v=kQuCOFzWoa0)**
 </span>
 <span style="font-size: 43.0;">
     # **[https://www.youtube.com/watch?v=RA_SpxP2t54](https://www.youtube.com/watch?v=RA_SpxP2t54)**
 </span> <span style="font-size: 43.0;">
     
**CODE: (Make sure to use Column vector standard)**
 </span>
 <span style="font-size: 36.0;">
     # **Faster when number of variables is small**
 </span>
# #include <bits/stdc++.h>
# using namespace std;
# #define REP(i,n) for(int i = 0; i < (n); i++)
# *const* int mod = 1e9 + 7;
# struct *Matrix* {
#     long long a[2][2] = {{0, 0},{0,0}};
#     *Matrix* operator *(*const* *Matrix&* other) {
#         *Matrix* product;
#         REP(i,2)REP(j,2)REP(k,2) {
#             product.a[i][k] = (product.a[i][k] +  (long long)a[i][j] * other.a[j][k])%mod;
#         }
#         return product;
#     }
# };
# *Matrix* expo_power(*Matrix* a, long long k) {
#     *Matrix* product;
#     REP(i,2) product.a[i][i] = 1;
#     while(k > 0) {
#         if(k % 2) {
#             product = product * a;
#         }
#         a = a * a;
#         k /= 2;
#     }
#     return product;
# }
# int main() {
#     long long n;
#     cin >> n;
#     *Matrix* single;
#     single.a[0][0] = 1;
#     single.a[0][1] = 1;
#     single.a[1][0] = 1;
#     single.a[1][1] = 0;
#     *Matrix* total = expo_power(single, n);
#     cout << total.a[1][0] << endl;
# }

 <span style="font-size: 36.0;">
     # **When number of variables is large (generalised)**
 </span>
#include <bits/stdc++.h>
# using namespace std;
# #define REP(i,n) for(int i = 0; i < (n); i++)
# *const* int mod = 1e9 + 7;
# struct *Matrix* {
#     int size;
#     vector<vector<int>> a;
#     Matrix(int _size){
#         size = _size;
#         a.assign(size, vector<int>(size, 0));
#     }
#     *Matrix* operator *(*const* *Matrix&* other) {
#         *Matrix* product(size);
#         REP(i,size)REP(j,size)REP(k,size) {
#             product.a[i][k] = (product.a[i][k] +  (long long)a[i][j] * other.a[j][k])%mod; // or whatever the dp transition logic is (can also be combination of minmax and +*)
#         }
#         return product;
#     }
# };
# *Matrix* expo_power(*Matrix* a, long long k) {
#     *Matrix* product(a.size);
#     REP(i,a.size) product.a[i][i] = 1;
#     while(k > 0) {
#         if(k % 2) {
#             product = product * a;
#         }
#         a = a * a;
#         k /= 2;
#     }
#     return product;
# }
# int main() {
#     long long n, m, k;
#     cin >> n >> m >> k;
#     *Matrix* single(n);
#     for(int i = 0; i<m; i++){
#         int u, v; cin >> u >> v;
#         u--;
#         v--;
#         single.a[u][v] = 1;
#     }
#     *Matrix* total = expo_power(single, k);
#     long long sum = 0;
#     for(int i = 0; i<n; i++){
#         for(int j = 0; j<n; j++){
#             sum += total.a[i][j];
#             sum %= mod;
#         }
#     }
#     cout << sum << "\n";
# }
# 
 <span style="font-family: .AppleSystemUIFont; font-size: 33.0;">
     # 

 </span> <span style="font-size: 42.0;">
     # **THEORY:
a[i][j] of matrix to power k => contribution to state variable i from state variable j over K length path.** 

 </span> <span style="font-size: 42.0;">
     # **(If single matrix is populated in similar way)
{If you use the directed adjacency matrix (storing nodes you have an out-edge to), then the logic is reverse, and in that case, a[i][j] is contribution from i to j }**
 </span>
# ![6A742F7A-591A-4A5F-A4BC-D2D1786B5AF2](images/6A742F7A-591A-4A5F-A4BC-D2D1786B5AF2.png)
# ![FF32CB37-8096-423C-9656-416E6E35F03F](images/FF32CB37-8096-423C-9656-416E6E35F03F.png)
# ![8F221793-953A-44BF-89DC-803E3A213703](images/8F221793-953A-44BF-89DC-803E3A213703.png)
 <span style="font-family: .AppleSystemUIFont; font-size: 31.0;">
     # tool to speed up the dp with constant space

 </span> <span style="font-family: .AppleSystemUIFont; font-size: 31.0;">
     # 
The variables that we need to store are all the variables that we would’ve needed to use to calculate dp in O(N) time and O(1) space.

 </span> <span style="font-family: .AppleSystemUIFont; font-size: 31.0;">
     The single column vector becomes all these variables.

 </span>![D20264FD-CF7C-45AF-AEA7-3D53C290EB63](images/D20264FD-CF7C-45AF-AEA7-3D53C290EB63.png)
![52C098E7-D68A-4326-8B76-ED13BFC0DA41](images/52C098E7-D68A-4326-8B76-ED13BFC0DA41.png)
 <span style="font-size: 43.0;">
     # **[https://codeforces.com/blog/entry/80195](https://codeforces.com/blog/entry/80195)**
 </span>

 <span style="font-size: 43.0;">
     **Can be done on any Small space DP, where the function is associative:**

 </span> <span style="font-size: 25.0;">
     [https://codeforces.com/gym/102644/problem/F](https://codeforces.com/gym/102644/problem/F)
 </span>
![017A691D-0515-4D82-AA60-EC880ACB18D3](images/017A691D-0515-4D82-AA60-EC880ACB18D3.png)
 <span style="font-size: 43.0;">
     **This, above, is an example of function being min, which is associative (min over sum of different paths)**

 </span>
 <span style="font-size: 43.0;">
     **Good problem to understand how to fit some dps into the matrix multiplication format:**

 </span>![02EB700F-0E3C-4B07-B21A-ED9B1E76CDF2](images/02EB700F-0E3C-4B07-B21A-ED9B1E76CDF2.png)





![AC101508-7D68-46A6-8C4E-F055A899A035](images/AC101508-7D68-46A6-8C4E-F055A899A035.png)
![FD5692F5-79F4-42A2-9CA9-B9618D339944](images/FD5692F5-79F4-42A2-9CA9-B9618D339944.png)


 <span style="font-size: 33.0;">
     # **Really Good for Learning about a trick ( converting exactly K to atmost K) and about Matrix Multiplication. ( can watch errichto video on matrix Exponentiation )**

 </span> <span style="font-size: 33.0;">
     **The trick is to have an extra node, and have all nodes have an edge to this special node ( even special node has an edge to special node ). And now find for paths of len K+1, to this special node.**
 </span>
![82BE2F0C-916E-48EF-9DA7-BFF3BAEF850F](images/82BE2F0C-916E-48EF-9DA7-BFF3BAEF850F.png)
![3800D3F2-6B76-4F84-AC5F-0B4567B682BB](images/3800D3F2-6B76-4F84-AC5F-0B4567B682BB.png)
