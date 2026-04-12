// Polygon Lattice Points: Boundary and Inside
// Polygon Lattice Points:

Boundary and Inside

ll twice_area(vector<P>*&* polygon){
    ll ans = 0;
    int n = polygon.size();
    for(int i = 0; i<n; i++){
        P p1 = polygon[i];
        P p2 = polygon[(i + 1)%n];
        ans += p1*p2;
    }
    ans = abs(ans);
    return ans;
}
void test_case(){ // foruma => Area = (inside) + (boundary / 2) - 1
    // or 2inside = 2area + 2 - boundary*
    ll n; cin >> n;
    vector<P> polygon(n);
    for(P& p : polygon){
        p.read();
    }
    ll boundary = 0;
    for(int i= 0; i<n; i++){
        P p1 = polygon[i];
        P p2 = polygon[(i+1)%n];
        p1 -= p2;
        boundary += gcd(abs(p1.x), abs(p1.y));
    }
    ll inside = (twice_area(polygon) + 2 - boundary)/2;
    cout << inside << " ";
    cout << boundary << endl;
}