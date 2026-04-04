# SEARCH IN ROTATED SORTED ARRAY


// if duplicates: 
bool searchInARotatedSortedArrayII(vector<int>&arr, int k) {
    int n = arr.size(); *// size of the array.*
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;

        *//if mid points the target*
        if (arr[mid] == k) return true;

        *//Edge case:*
        if (arr[low] == arr[mid] && arr[mid] == arr[high]) {
            low = low + 1;
            high = high - 1;
            continue;
        }

        *//if left part is sorted:*
        if (arr[low] <= arr[mid]) {
            if (arr[low] <= k && k <= arr[mid]) {
                *//element exists:*
                high = mid - 1;
            }
            else {
                *//element does not exist:*
                low = mid + 1;
            }
        }
        else { *//if right part is sorted:*
            if (arr[mid] <= k && k <= arr[high]) {
                *//element exists:*
                low = mid + 1;
            }
            else {
                *//element does not exist:*
                high = mid - 1;
            }
        }
    }
    return false;
}


// if no duplicates, but also want index.
int search(vector<int>& arr, int n, int k) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;

        *//if mid points the target*
        if (arr[mid] == k) return mid;

        *//if left part is sorted:*
        if (arr[low] <= arr[mid]) {
            if (arr[low] <= k && k <= arr[mid]) {
                *//element exists:*
                high = mid - 1;
            }
            else {
                *//element does not exist:*
                low = mid + 1;
            }
        }
        else { *//if right part is sorted:*
            if (arr[mid] <= k && k <= arr[high]) {
                *//element exists:*
                low = mid + 1;
            }
            else {
                *//element does not exist:*
                high = mid - 1;
            }
        }
    }
    return -1;
}


int findMin(vector<int>& arr) {
    int low = 0, high = arr.size() - 1;
    int ans = INT_MAX;
    while (low <= high) {
        int mid = (low + high) / 2;
        *//search space is already sorted*
        *//then arr[low] will always be*
        *//the minimum in that search space:*
        if (arr[low] <= arr[high]) {
            ans = min(ans, arr[low]);
            break;
        }

        *//if left part is sorted:*
        if (arr[low] <= arr[mid]) {
            *// keep the minimum:*
            ans = min(ans, arr[low]);

            *// Eliminate left half:*
            low = mid + 1;
        }
        else { *//if right part is sorted:*

            *// keep the minimum:*
            ans = min(ans, arr[mid]);

            *// Eliminate right half:*
            high = mid - 1;
        }
    }
    return ans;
}
# **Same algo (but this time we calc index of min value)**
int findKRotation(vector<int> &arr) {
    int low = 0, high = arr.size() - 1;
    int ans = INT_MAX;
    int index = -1;
    while (low <= high) {
        int mid = (low + high) / 2;
        *//search space is already sorted*
        *//then arr[low] will always be*
        *//the minimum in that search space:*
        if (arr[low] <= arr[high]) {
            if (arr[low] < ans) {
                index = low;
                ans = arr[low];
            }
            break;
        }

        *//if left part is sorted:*
        if (arr[low] <= arr[mid]) {
            *// keep the minimum:*
            if (arr[low] < ans) {
                index = low;
                ans = arr[low];
            }

            *// Eliminate left half:*
            low = mid + 1;
        }
        else { *//if right part is sorted:*

            *// keep the minimum:*
            if (arr[mid] < ans) {
                index = mid;
                ans = arr[mid];
            }

            *// Eliminate right half:*
            high = mid - 1;
        }
    }
    return index;
}


