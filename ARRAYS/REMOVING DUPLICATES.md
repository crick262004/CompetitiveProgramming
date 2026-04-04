# REMOVING DUPLICATES


sort(vals.begin(), vals.end());
vals.erase(unique(vals.begin(), vals.end()), vals.end());



int removeDuplicates(int arr[], int n)
{
  int i = 0;
  for (int j = 1; j < n; j++) {
    if (arr[i] != arr[j]) {
      i++;
      arr[i] = arr[j];
    }
  }
  return i + 1;
}