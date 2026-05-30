# SPARSE TABLE: (sid calls this RMQ)



int lg[MAXN+1];
lg[1] = 0;
for (int i = 2; i <= MAXN; i++)
    lg[i] = lg[i/2] + 1;

int K = lg[MAXN];
int st[K + 1][MAXN];
std::copy(a.begin(), a.end(), st[0]);
for (int i = 1; i <= K; i++)
    for (int j = 0; j + (1 << i) <= MAXN; j++)
        st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);

int i = lg[r - l + 1]; 
int minimum = min(st[i][l], st[i][r - (1 << i) + 1]);




![E8520961-F04C-451D-9DDA-B34662D9CF59](images/E8520961-F04C-451D-9DDA-B34662D9CF59.png)


# ![993C52D4-F838-4508-8927-3C6E787D8112](images/993C52D4-F838-4508-8927-3C6E787D8112.png)
![37A7927C-9AAE-40BE-A412-BA70580D28A8](images/37A7927C-9AAE-40BE-A412-BA70580D28A8.png)
# ![255680C4-ACB4-49F3-94FC-0A668D78B24C](images/255680C4-ACB4-49F3-94FC-0A668D78B24C.png)
# ![BFCB649C-B1BF-4FDE-87FA-9A6411172802](images/BFCB649C-B1BF-4FDE-87FA-9A6411172802.png)
# Range Sum:
![14262D19-A473-4284-A6A4-6B7C5AD7C67E](images/14262D19-A473-4284-A6A4-6B7C5AD7C67E.png)
long long st[K + 1][MAXN];
std::copy(array.begin(), array.end(), st[0]);
for (int i = 1; i <= K; i++)
    for (int j = 0; j + (1 << i) <= N; j++)
        st[i][j] = st[i - 1][j] + st[i - 1][j + (1 << (i - 1))];


long long sum = 0;
for (int i = K; i >= 0; i--) {
    if ((1 << i) <= R - L + 1) {
        sum += st[i][L];
        L += 1 << i;
    }
}


# Range Minimum:
![1EB5444B-8F1F-4450-89CF-4D62E3EE0FC4](images/1EB5444B-8F1F-4450-89CF-4D62E3EE0FC4.png)
int lg[MAXN+1];
lg[1] = 0;
for (int i = 2; i <= MAXN; i++)
    lg[i] = lg[i/2] + 1;
![2C8F7F57-EE51-4300-943D-14BCF46FF557](images/2C8F7F57-EE51-4300-943D-14BCF46FF557.png)
int K = lg[MAXN];
int st[K + 1][MAXN];
std::copy(a.begin(), a.end(), st[0]);
for (int i = 1; i <= K; i++)
    for (int j = 0; j + (1 << i) <= MAXN; j++)
        st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);


int i = lg[r - l + 1];
int minimum = min(st[i][l], st[i][r - (1 << i) + 1]);


 <span style="font-family: .AppleSystemUIFont; font-size: 33.0;">
     A sparse table is calculated using a D&C DP in bottom-up tabulation style.
 </span>
