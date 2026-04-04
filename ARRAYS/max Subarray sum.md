# max Subarray sum


long long maxSubarraySum(int arr[], int n) {
    long long maxi = LONG_MIN; *// maximum sum*
    long long sum = 0;

    for (int i = 0; i < n; i++) {

        sum += arr[i];

        if (sum > maxi) {
            maxi = sum;
        }

        *// If sum < 0: discard the sum calculated*
        if (sum < 0) {
            sum = 0;
        }
    }

    *// To consider the sum of the empty subarray*
    *// uncomment the following check:*

    *//if (maxi < 0) maxi = 0;*

    return maxi;
}


long long maxSubarraySum(int arr[], int n) {
    long long maxi = LONG_MIN; *// maximum sum*
    long long sum = 0;

    int start = 0;
    int ansStart = -1, ansEnd = -1;
    for (int i = 0; i < n; i++) {

        if (sum == 0) start = i; *// starting index*

        sum += arr[i];

        if (sum > maxi) {
            maxi = sum;

            ansStart = start;
            ansEnd = i;
        }

        *// If sum < 0: discard the sum calculated*
        if (sum < 0) {
            sum = 0;
        }
    }

    *// To consider the sum of the empty subarray*
    *// uncomment the following check:*
    *//if (maxi < 0) maxi = 0;*

    return maxi;
}
