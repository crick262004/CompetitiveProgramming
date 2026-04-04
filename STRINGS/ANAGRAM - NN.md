# ANAGRAM : NN


bool isAnagram(string s, string t) {
    int n = s.length();
    int m = t.length();

    if(m!= n)
        return false;

    unordered_map <char, int> m1;
    // unordered_map <char, int> m2;

    for(int i =0; i<n; i++)
    {
        m1[s[i]] ++;
        m1[t[i]] --;
    }

    for(int i = 0; i<n; i++)
    {
        if(m1[s[i]] != 0)
            return false;
    }
    return true;
}
