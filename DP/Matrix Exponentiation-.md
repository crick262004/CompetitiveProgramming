# Matrix Exponentiation

## References
- [https://www.youtube.com/watch?v=kQuCOFzWoa0](https://www.youtube.com/watch?v=kQuCOFzWoa0)
- [https://www.youtube.com/watch?v=RA_SpxP2t54](https://www.youtube.com/watch?v=RA_SpxP2t54)

## Code
Use column vector standard.

### Faster when number of variables is small
```cpp
#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for (int i = 0; i < (n); i++)
const int mod = 1e9 + 7;

struct Matrix {
     long long a[2][2] = {{0, 0}, {0, 0}};

     Matrix operator*(const Matrix& other) {
          Matrix product;
          REP(i, 2) REP(j, 2) REP(k, 2) {
               product.a[i][k] = (product.a[i][k] + (long long)a[i][j] * other.a[j][k]) % mod;
          }
          return product;
     }
};

Matrix expo_power(Matrix a, long long k) {
     Matrix product;
     REP(i, 2) product.a[i][i] = 1;
     while (k > 0) {
          if (k % 2) {
               product = product * a;
          }
          a = a * a;
          k /= 2;
     }
     return product;
}

int main() {
     long long n;
     cin >> n;

     Matrix single;
     single.a[0][0] = 1;
     single.a[0][1] = 1;
     single.a[1][0] = 1;
     single.a[1][1] = 0;

     Matrix total = expo_power(single, n);
     cout << total.a[1][0] << endl;
}
```

### When number of variables is large (generalized)
```cpp
#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for (int i = 0; i < (n); i++)
const int mod = 1e9 + 7;

struct Matrix {
     int size;
     vector<vector<int>> a;

     Matrix(int _size) {
          size = _size;
          a.assign(size, vector<int>(size, 0));
     }

     Matrix operator*(const Matrix& other) {
          Matrix product(size);
          REP(i, size) REP(j, size) REP(k, size) {
               product.a[i][k] = (product.a[i][k] + (long long)a[i][j] * other.a[j][k]) % mod;
          }
          return product;
     }
};

Matrix expo_power(Matrix a, long long k) {
     Matrix product(a.size);
     REP(i, a.size) product.a[i][i] = 1;
     while (k > 0) {
          if (k % 2) {
               product = product * a;
          }
          a = a * a;
          k /= 2;
     }
     return product;
}

int main() {
     long long n, m, k;
     cin >> n >> m >> k;

     Matrix single(n);
     for (int i = 0; i < m; i++) {
          int u, v;
          cin >> u >> v;
          u--;
          v--;
          single.a[u][v] = 1;
     }

     Matrix total = expo_power(single, k);
     long long sum = 0;
     for (int i = 0; i < n; i++) {
          for (int j = 0; j < n; j++) {
               sum += total.a[i][j];
               sum %= mod;
          }
     }
     cout << sum << "\n";
}
```

## Theory
`a[i][j]` of `matrix^k` is the contribution to state variable `i` from state variable `j` over paths of length `K`.

If the single matrix is populated in the opposite direction, the logic is reversed: `a[i][j]` becomes the contribution from `i` to `j`.

![6A742F7A-591A-4A5F-A4BC-D2D1786B5AF2](images/6A742F7A-591A-4A5F-A4BC-D2D1786B5AF2.png)
![FF32CB37-8096-423C-9656-416E6E35F03F](images/FF32CB37-8096-423C-9656-416E6E35F03F.png)
![8F221793-953A-44BF-89DC-803E3A213703](images/8F221793-953A-44BF-89DC-803E3A213703.png)

## Constant Space DP Intuition
The variables that we need to store are the same variables we would need to calculate DP in `O(N)` time and `O(1)` space.
The single column vector becomes all these variables.

![D20264FD-CF7C-45AF-AEA7-3D53C290EB63](images/D20264FD-CF7C-45AF-AEA7-3D53C290EB63.png)
![52C098E7-D68A-4326-8B76-ED13BFC0DA41](images/52C098E7-D68A-4326-8B76-ED13BFC0DA41.png)

## More References
- [https://codeforces.com/blog/entry/80195](https://codeforces.com/blog/entry/80195)
- Can be done on any small-space DP where the function is associative.
- [https://codeforces.com/gym/102644/problem/F](https://codeforces.com/gym/102644/problem/F)

![017A691D-0515-4D82-AA60-EC880ACB18D3](images/017A691D-0515-4D82-AA60-EC880ACB18D3.png)

This is an example of a function being min, which is associative (`min` over sum of different paths).

Good problem to understand how to fit some DPs into the matrix multiplication format:

![02EB700F-0E3C-4B07-B21A-ED9B1E76CDF2](images/02EB700F-0E3C-4B07-B21A-ED9B1E76CDF2.png)
![AC101508-7D68-46A6-8C4E-F055A899A035](images/AC101508-7D68-46A6-8C4E-F055A899A035.png)
![FD5692F5-79F4-42A2-9CA9-B9618D339944](images/FD5692F5-79F4-42A2-9CA9-B9618D339944.png)

## Trick
Really good for learning about the trick of converting exactly `K` to at most `K`, and about matrix multiplication.

The trick is to add an extra node, connect all nodes to this special node, and let the special node connect to itself. Then find paths of length `K+1` to that special node.

![82BE2F0C-916E-48EF-9DA7-BFF3BAEF850F](images/82BE2F0C-916E-48EF-9DA7-BFF3BAEF850F.png)
![3800D3F2-6B76-4F84-AC5F-0B4567B682BB](images/3800D3F2-6B76-4F84-AC5F-0B4567B682BB.png)
