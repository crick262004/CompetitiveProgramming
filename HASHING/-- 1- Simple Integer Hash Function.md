# // 1. Simple Integer Hash Function



struct *HashInt* {
    int operator () (int x) {
        x^=(x>>13); *// A simple bit shift to scramble the number*
        return x;
    }
};

*// 2. Custom Static Hash Table*
*// Key=int, Value=int, N=Max Elements, mod=Bucket Size*
template <typename *Key*,typename *Value*,typename *Hash*,int N,int mod>
struct HashTable {
    int head[mod+5]; *// Head of linked list for each bucket*
    int nxt[N+5];    *// Next pointer for linked list*
    *Value* val[N+5];  *// Stored values*
    *Key* key[N+5];    *// Stored keys*
    *Hash* hash;       *// The hash function*
    int cnt;         *// How many elements currently stored*

    HashTable():cnt(1){}

    *// Get reference to value (create if doesn't exist)*
    *inline* *Value&* at(*const* *Key* *&*k) {
        int t=hash(k)%mod;
        for(int i=head[t];i;i=nxt[i]) {
            if(key[i]==k) return val[i];
        }
        *// If not found, add new*
        key[cnt]=k;
        nxt[cnt]=head[t];
        head[t]=cnt;
        assert(cnt<=N); *// Crash if we exceed capacity*
        return val[cnt++];
    }

    *inline* *Value&* operator [] (*const* *Key* *&*k) { return at(k); }

    *inline* void clear() {
        cnt=1;
        memset(head,0,sizeof(head));
    }
};
