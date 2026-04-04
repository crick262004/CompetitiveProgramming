# LOWER BOUND : finds the first element in a sorted range that is not…

# **LOWER BOUND : finds the first element in a sorted range that is not less than a given value, returning an iterator to that element**

int p = lower_bound(begin(a), end(a), v) - begin(a);
int p = lower_bound(all(a), v) - a.begin();



int lowerBound(vector<int> arr, int n, int x) {
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = (low + high) / 2;
        *// maybe an answer*
        if (arr[mid] >= x) {
            ans = mid;
            *//look for smaller index on the left*
            high = mid - 1;
        }
        else {
            low = mid + 1; *// look on the right*
        }
    }
    return ans;
}
