// Point wrt Line
// 
// include <bits/stdc++.h>

using namespace std;

struct P{
    long long x, y; 
    void read(){
        cin >> x >> y;
    }
    P operator - (const P& b) const{
        return P{x - b.x, y - b.y};
    }
    void operator -= (const P& b) {
        x -= b.x;
        y -= b.y;
    }
    long long operator * (const P& b) const{ // vector product aka cross product aka right hand curling 
        return x*b.y - y*b.x;
    }
};

void test_case(){
    P p1, p2, p3;
    p1.read();
    p2.read();
    p3.read();
    p2 -= p1;
    p3 -= p1;
    long long cross_product = p2*p3;
    if(cross_product < 0){ // thumb going inwards
        cout <<"RIGHT" << "\n";
    } else if(cross_product > 0){ // thumb going outwards
        cout <<"LEFT" << "\n";
    } else{
        cout <<"TOUCH" << "\n";
    }
}

int main(){
    int T;
    cin >> T;
    while(T--){
        test_case();
    }
}