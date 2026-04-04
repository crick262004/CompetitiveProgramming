# BUBBLE SORT : maybe


 <span style="font-size: 22.0;text-align: left;">
     void bubble_sort(int arr[], int n) {
    
 </span> <span style="font-size: 22.0;text-align: left;">
     *// bubble sort*
 </span> <span style="font-size: 22.0;text-align: left;">
     
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j <= i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }

 </span> <span style="font-size: 22.0;">
     }
 </span>