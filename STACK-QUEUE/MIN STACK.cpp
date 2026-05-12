// MIN STACK

class MinStack {
    stack<pair<int, int>> st;

public:
    void push(int x) {
        int min_val;
        if (st.empty()) {
            min_val = x;
        } else {
            min_val = std::min(st.top().second, x);
        }
        st.push({x, min_val});
    }

    void pop() {
        st.pop();
    }

    int top() {
        return st.top().first;
    }

    int getMin() {
        return st.top().second;
    }
};
