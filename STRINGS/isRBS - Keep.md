# isRBS : Keep


  auto check = `[](const string& s)` {
    int bal = 0;
    for (char c : s) {
      if (c == '(') ++bal;
      if (c == ')') --bal;
      if (bal < 0) return false;
    }
    return bal == 0;
 <span style="font-family: .AppleSystemUIFont; font-size: 13.0;">
     ##   };
 </span>
