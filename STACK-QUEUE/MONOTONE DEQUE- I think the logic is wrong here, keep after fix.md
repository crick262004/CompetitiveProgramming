# MONOTONE DEQUE: I think the logic is wrong here, keep after fix

struct *monotone_deque*{
    *// min deque*

    deque<int> dq;
    void insert(int x){
        while(!dq.empty() && dq.back() > x)
            dq.pop_back();
        dq.push_back(x);
    }
    void remove(int x){
        if(!dq.empty()){
            if(dq.front() == x)
                dq.pop_back();
        }
    }
    int getmin(){
        if(!dq.empty()){
            return dq.front();
        } else{
            return 0;
        }
    }
};
