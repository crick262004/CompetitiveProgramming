# SUM OF SUBARRAYS’ MINIMUMS

# SUM OF SUBARRAYS’ MAXIMUMS
# SUM OF SUBARRAYS’ RANGES



vector<int> nextSmallerElement(vector<int>& arr){
        vector<int> nse(arr.size());
        stack<int> st;
        for(int i = arr.size()-1; i>=0; i--)
        {
            while(!st.empty() && arr[i] <= arr[st.top()])
                st.pop();
            nse[i] = st.empty()? arr.size() : st.top();
            st.push(i);
        }
        return nse;
    }
    vector<int> nextGreaterElement(vector<int>& arr){
        vector<int> nge(arr.size());
        stack<int> st;
        for(int i = arr.size()-1; i>=0; i--)
        {
            while(!st.empty() && arr[i] >= arr[st.top()])
                st.pop();
            nge[i] = st.empty()? arr.size() : st.top();
            st.push(i);
        }
        return nge;
    }
    vector<int> prevSmallerElement(vector<int>& arr){
        vector<int> psee(arr.size());
        stack<int> st;
        for(int i = 0; i<arr.size(); i++)
        {
            while(!st.empty() && arr[i] < arr[st.top()])
                st.pop();
            psee[i] = st.empty()? -1 : st.top();
            st.push(i);
        }
        return psee;
    }   
    vector<int> prevGreaterElement(vector<int>& arr){
        vector<int> pgee(arr.size());
        stack<int> st;
        for(int i = 0; i<arr.size(); i++)
        {
            while(!st.empty() && arr[i] > arr[st.top()])
                st.pop();
            pgee[i] = st.empty()? -1 : st.top();
            st.push(i);
        }
        return pgee;
    }
    long long sumSubarrayMins(vector<int>& arr) {
        vector<int> psee = prevSmallerElement(arr);
        vector<int> nse = nextSmallerElement(arr);
        long long sum = 0;
        for(int i = 0; i< arr.size(); i++)
        {
            int left = i - psee[i];
            int right = nse[i] - i;
            sum = (( ( (long long)1 * left * right) * arr[i]) + sum);
        }
        return sum;
    }
    long long sumSubarrayMaxs(vector<int>& arr) {
        vector<int> pgee = prevGreaterElement(arr);
        vector<int> nge = nextGreaterElement(arr);
        long long sum = 0;
        for(int i = 0; i< arr.size(); i++)
        {
            int left = i - pgee[i];
            int right = nge[i] - i;
            sum = (( ( (long long)1 * left * right) * arr[i]) + sum);
        }
        return sum;
    }
    long long subArrayRanges(vector<int>& nums) {
        long long minsum = sumSubarrayMins(nums);
        long long maxsum = sumSubarrayMaxs(nums);
        return maxsum - minsum;
    }
