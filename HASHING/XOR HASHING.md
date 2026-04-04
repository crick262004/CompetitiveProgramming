# XOR HASHING


    *random_device* rd; 
    *mt19937_64* gen(rd());
    map<unsigned long long,pair< unsigned long long,unsigned long long >> mapping;
    set<pair <unsigned long long,unsigned long long>> used; used.insert({0, 0});
    vector<pair <unsigned long long,unsigned long long>> pfx(n);

    for (int i = 0; i<n; i++){
        int c = v[i];
        pair <unsigned long long,unsigned long long> random;
        if (mapping.find(c) == mapping.end()){
            do{
                random = {gen(), gen()};
            }while (used.find(random) != used.end());
            used.insert(random);
            mapping[c] = random;
        }else{
            random = mapping[c];
        }
        pfx[i] = random;
    }
    for (int i=0;i<n;i++){
        if(i){
            pfx[i].first = pfx[i-1].first ^ pfx[i].first;
            pfx[i].second = pfx[i-1].second ^ pfx[i].second;
        }
    }
    
    for (int i=0;i<q;i++){
        int l, r; cin >> l >> r;
        l--; r--;
        pair <unsigned long long,unsigned long long> ans = pfx[r];
        pair <unsigned long long,unsigned long long> ch = {0, 0};
        if(l){
            ans.first ^= pfx[l-1].first;
            ans.second ^= pfx[l-1].second;
        }
        if(ans == ch ) 
            cout << "YES" << "\n";
        else{
            cout << "NO" << "\n";
        }
    }



WEAKER METHOD : 

    *vpi* px(n);
    int K1 = 1432570;
    int M1 = 1e9 + 21;
    int K2 = 22370123;
    int M2 = 1e9 + 9;

    f(i,n){
        px[i] = { (a[i] + K1)%M1 , (a[i] + K2)%M2 };
        if(i){
            px[i].ff = px[i-1].ff ^ px[i].ff;
            px[i].ss = px[i-1].ss ^ px[i].ss;
        }
    }

    f(i,q){
        ll l, r; cin >> l >> r;
        l--; r--;
        *pi* ans = px[r];
        *pi* ch = {0, 0};
        if(l){
            ans.ff ^= px[l-1].ff;
            ans.ss ^= px[l-1].ss;
        }
        if(ans == ch ) 
            cyes;
        else{
            cno;
        }
    }

