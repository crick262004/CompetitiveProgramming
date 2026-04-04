# SORT K SORTED ARRAYS : Keep


 <span style="font-size: 21.0;">
     //Function to merge k sorted arrays.
vector<int> mergeKArrays(vector<vector<int>> arr, int k)
{
    //code here
    priority_queue<int, vector<int>, greater<int> > minheap;
    for(int i = 0; i < k; i++)
    {
        for(int j = 0; j<k; j++)
        {
            minheap.push(arr[i][j]);
        }
    }
    vector<int> ans;
    while(!minheap.empty())
    {
        ans.push_back(minheap.top());
        minheap.pop();
    }
    return ans;
}
 </span>