# ROTATE K


*// Function to Rotate k elements to right*
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();

        k = k % n;

        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }

*// Function to Rotate k elements to left*
void Rotateeletoleft(int arr[], int n, int k)
{
  *// Reverse first k elements*
  Reverse(arr, 0, k - 1);
  *// Reverse last n-k elements*
  Reverse(arr, k, n - 1);
  *// Reverse whole array*
  Reverse(arr, 0, n - 1);
}
