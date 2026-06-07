#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// --- STRIVER'S WAY (INDEX STYLE) ---

// Next Greater Element // index
vector<int> nextGreaterElement(vector<int>& arr) {
    vector<int> nge(arr.size());
    stack<int> st;
    for(int i = arr.size()-1; i>=0; i--) {
        while(!st.empty() && arr[i] >= arr[st.top()])
            st.pop();
        nge[i] = st.empty() ? arr.size() : st.top();
        st.push(i);
    }
    return nge;
}

// Next Smaller Element // index
vector<int> nextSmallerElement(vector<int>& arr) {
    vector<int> nse(arr.size());
    stack<int> st;
    for(int i = arr.size()-1; i>=0; i--) {
        while(!st.empty() && arr[i] <= arr[st.top()])
            st.pop();
        nse[i] = st.empty() ? arr.size() : st.top();
        st.push(i);
    }
    return nse;
}

// Previous Greater Element or Equal: // index
vector<int> prevGreaterElement(vector<int>& arr) {
    vector<int> pgee(arr.size());
    stack<int> st;
    for(int i = 0; i<arr.size(); i++) {
        while(!st.empty() && arr[i] > arr[st.top()]) // change to >= for strict Greater
            st.pop();
        pgee[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    return pgee;
}

// Previous Smaller Element or Equal: // index
vector<int> prevSmallerElement(vector<int>& arr) {
    vector<int> psee(arr.size());
    stack<int> st;
    for(int i = 0; i<arr.size(); i++) {
        while(!st.empty() && arr[i] < arr[st.top()]) // change to <= for strict Smaller
            st.pop();
        psee[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    return psee;
}

// --- MY WAY (INDEX STYLE) ---

// NGE my way // index style
vector<int> nextGreaterElementMyWay(vector<int>& nums) {
    stack<int> stk;
    int n = nums.size();
    vector<int> nge(n, -1);
    for(int i = 0; i<n; i++) {
        int val = nums[i];
        while(!stk.empty() && val > nums[stk.top()]) {
            nge[stk.top()] = i;
            stk.pop();
        }
        stk.push(i);
    }
    while(!stk.empty()) {
        nge[stk.top()] = -1;
        stk.pop();
    }
    return nge;
}

// --- STRIVER'S WAY (VALUE STYLE) ---
vector<int> nextGreaterElementsValues(vector<int>& nums) {
    int n = nums.size();
    vector<int> nge(n, -1);
    stack<int> st;
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && st.top() <= nums[i % n]) {
            st.pop();
        }
        if (!st.empty()) nge[i] = st.top();
        st.push(nums[i]);
    }
    return nge;
}

// --- PSE (VALUE STYLE) ---
vector<int> prevSmallerValues(vector<int>& A) {
    int n = A.size();
    vector<int> G(n, -1);
    stack<int> st;
    
    for(int i = 0; i<n; i++) {
        if(i == 0)
            st.push(A[i]);
        else {
            while(!st.empty() && A[i] <= st.top())
                st.pop();
            if(st.empty())
                st.push(A[i]);
            else {
                G[i] = st.top();
                st.push(A[i]);
            }
        }
    }
    return G;
}

int main() {
    return 0;
}