# Adjacents dependent

 // THIS IS A TEMPLATE FOR BS WHERE WE HAVE TO COMPARE VALUE WITH NEIGHBOURS.


int singleNonDuplicate(vector<int>& arr) {
    int n = arr.size(); *//size of the array.*

    *//Edge cases:*
    if (n == 1) return arr[0];
    if (arr[0] != arr[1]) return arr[0];
    if (arr[n - 1] != arr[n - 2]) return arr[n - 1];

    int low = 1, high = n - 2;
    while (low <= high) {
        int mid = (low + high) / 2;

        *//if arr[mid] is the single element:*
        if (arr[mid] != arr[mid + 1] && arr[mid] != arr[mid - 1]) {
            return arr[mid];
        }

        *//we are in the left:*
        if ((mid % 2 == 1 && arr[mid] == arr[mid - 1])
                || (mid % 2 == 0 && arr[mid] == arr[mid + 1])) {
            *//eliminate the left half:*
            low = mid + 1;
        }
        *//we are in the right:*
        else {
            *//eliminate the right half:*
            high = mid - 1;
        }
    }

    *// dummy return statement:*
    return -1;
}


int findPeakElement(vector<int> &arr) {
    int n = arr.size(); *//Size of array.*

    *// Edge cases:*
    if (n == 1) return 0;
    if (arr[0] > arr[1]) return 0;
    if (arr[n - 1] > arr[n - 2]) return n - 1;

    int low = 1, high = n - 2;
    while (low <= high) {
        int mid = (low + high) / 2;

        *//If arr[mid] is the peak:*
        if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1])
            return mid;

        *// If we are in the left:*
        if (arr[mid] > arr[mid - 1]) low = mid + 1;

        *// If we are in the right:*
        *// Or, arr[mid] is a common point:*
        else high = mid - 1;
    }
    *// Dummy return statement*
    return -1;
}



