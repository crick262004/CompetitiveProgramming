# INSERTION SORT : maybe, isnt this just opposite traversal, same algo…

 <span style="font-size: 30.0;">
     # **INSERTION SORT : maybe, isnt this just opposite traversal, same algo as Bubble sort?**

 </span>
 <span style="font-size: 23.0;text-align: left;">
     void insertion_sort(int arr[], int n) {
    for (int i = 0; i <= n - 1; i++) {
        int j = i;
        while (j > 0 && arr[j - 1] > arr[j]) {
            int temp = arr[j - 1];
            arr[j - 1] = arr[j];
            arr[j] = temp;
            j--;
        }
    }

 </span> <span style="font-size: 23.0;">
     }
 </span>