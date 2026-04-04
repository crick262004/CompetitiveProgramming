# ISOMORPHIC STRINGS : NN



bool isIsomorphic(string s, string t) {
    int n1 = s.length();
    int n2 = t.length();

    if(n1 != n2)
        return false;
    
    unordered_map<char, char> StoT;
    unordered_map<char, char> TtoS;

    for(int i = 0; i<n1; i++)
    {
        char chs = s[i];
        char cht = t[i];
        if(StoT.find(chs) != StoT.end() && StoT[chs] != cht)
            return false;
        if(TtoS.find(cht) != StoT.end() &&  TtoS[cht] != chs)
            return false;
        StoT[s[i]] = t[i];
        TtoS[t[i]] = s[i];
    }
    return true;
}
