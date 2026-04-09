# Attavar : (Easy)

**2 files, but very simple**

`temp.cpp`:
```cpp
#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int randint(int l, int r) {
    return rng() % (r - l + 1) + l;
}

int main() {
    int t = 100;
    cout << t << endl;
    while (t--) {
        int n = 100;
        cout << n << endl;
        for (int i = 0; i < n; i++) {
            cout << randint(0, 2 * n) << ' ';
        }
        cout << endl;
    }
}
```

`temp.py`:
```python
from random import randint, shuffle
t = 100
print(t)
for _ in range(t):
    n = 100
    print(n)
    # a = [randint(0, 2 * n) for _ in range(n)]
    a = [i for i in range(n)]
    shuffle(a)
    print(*a)
```

```bash
py temp.py > testcases.in 
g++ file.cpp && ./a.out < testcases.in 
```
