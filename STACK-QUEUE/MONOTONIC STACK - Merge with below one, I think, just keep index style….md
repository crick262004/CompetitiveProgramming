# MONOTONIC STACK : Merge with below one, I think, just keep index style…

 <span style="font-size: 33.0;">
     # **MONOTONIC STACK : Merge with below one, I think, just keep index style, striver way, with my way commented out. Make class for all 4 types, and specify that for EE you need to change >= to > while popping**
 </span>

 <span style="font-size: 26.0;">
     # **NGE my way // index style**
 </span>
vector<int> nextGreaterElement(vector<int>& nums) {
    stack<int> stk;
    int n = nums.size();
    vector<int> nge(n, -1);
    for(int i = 0; i<n; i++)
    {
        int val = nums[i];
        while(!stk.empty() && val > nums[stk.top()]){
            nge[stk.top()] = i;
            stk.pop();
        }
        stk.push(i);
    }
    while(!stk.empty()){
        nge[stk.top()] = -1;
        stk.pop();
    }
    return nge;
}


 <span style="font-size: 26.0;">
     # **NGE striver way: // value style**
 </span>
vector < int > nextGreaterElements(vector < int > & nums) {
      int n = nums.size();
      vector < int > nge(n, -1);
      stack < int > st;
      for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && st.top() <= nums[i % n]) {
          st.pop();
        }
        if (!st.empty()) nge[i] = st.top();
       	st.push(nums[i]);
      }
      return nge;
    }

 <span style="font-size: 26.0;">
     # **PSE: // value**
 </span>
vector<int> Solution::prevSmaller(vector<int> &A) {
    int n = A.size();
    vector<int> G(n, -1);
    stack<int> st;
    
    for(int i = 0; i<n; i++)
    {
        if(i == 0)
            st.push(A[i]);
        else
        {
            while(!st.empty() && A[i] <= st.top())
                st.pop();
            if(st.empty())
                st.push(A[i]);
            else
            {
                G[i] = st.top();
                st.push(A[i]);
            }
        }
    }
    return G;
}