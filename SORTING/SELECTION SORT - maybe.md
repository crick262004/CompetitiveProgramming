# SELECTION SORT : maybe


 <span style="font-size: 23.0;text-align: left;">
     int[] selection_sort(int arr[], int n) {
  
 </span> <span style="font-size: 23.0;text-align: left;">
     *// selection sort*
 </span> <span style="font-size: 23.0;text-align: left;">
     
  for (int i = 0; i < n - 1; i++) {
    int mini = i;
    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[mini]) {
        mini = j;
      }
    }
    int temp = arr[mini];
    arr[mini] = arr[i];
    arr[i] = temp;
  }

 </span> <span style="font-size: 23.0;">
     return arr;

 </span> <span style="font-size: 23.0;text-align: left;">
     }

 </span>