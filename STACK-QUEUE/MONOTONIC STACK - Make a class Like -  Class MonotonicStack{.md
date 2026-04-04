# MONOTONIC STACK : Make a class Like :  Class MonotonicStack{

 <span style="font-size: 33.0;">
     # **MONOTONIC STACK : Make a class
Like : 
Class MonotonicStack{**

 </span> <span style="font-size: 33.0;">
     **public : 
	Constructor is called with vector, or without a vector
	push() -> here we implement the while loop logic
	getnge(int ind) -> returns index of nge of a[ind]
	pop() -> simple pop, rarely used
	top()
	isEmpty()
};
look at Monotonic Deque**

 </span> <span style="font-size: 33.0;">
     # **STRIVER’S WAY**
 </span>


 <span style="font-size: 26.0;">
     # **NGE // index**
 </span>
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


 <span style="font-size: 26.0;">
     # **NSE // index**
 </span>
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

 <span style="font-size: 26.0;">
     # **PGEE: // index**
 </span>

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


 <span style="font-size: 26.0;">
     # **PSEE: // index**
 </span>
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
