// Convex Hull

**Upper hull - Lower hull way ( sorting points by {x,y} )**

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
    long long triangle (const P& b, const P& c) const {
        return (b - *this) * (c - *this);
    }
    bool operator < (const P& b) const {
        return make_pair(x, y) < make_pair(b.x, b.y);
    }
};
void test_case(){
    ll n; cin >> n;
    vector<P> points(n);
    for(P& p : points){
        p.read();
    }
    sort(points.begin(), points.end()); // sort them from left to right, that is, in increasing x
    vector<P> hull;
    for(int rep = 0; rep < 2; rep++){ // first time upper hull, second time lower hull
        int S = hull.size();
        for(P p3 : points){
            while( ((int)hull.size() - S )>= 2){
                P p1 = hull.end()[-2];
                P p2 = hull.end()[-1];
                if(p1.triangle(p2,p3) <= 0){ // B on the left of C, or collinear
                    break; // cos good B
                }
                hull.pop_back(); // remove bad B
            }
            hull.push_back(p3);
        }
        hull.pop_back(); // remove rightmost point
        reverse(points.begin(), points.end()); // now we want to make lower hull
    }
    cout << hull.size() << endl;
    for(P p : hull){
        cout << p.x << " " << p.y << endl;
    }
}