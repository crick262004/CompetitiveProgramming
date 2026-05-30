// isRBS : Keep

bool check(const string& s) {
    int bal = 0;
    for (char c : s) {
        if (c == '(') ++bal;
        if (c == ')') --bal;
        if (bal < 0) return false;
    }
    return bal == 0;
}
