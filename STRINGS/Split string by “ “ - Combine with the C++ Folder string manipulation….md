# Split string by “ “ : Combine with the C++ Folder string manipulation…

# Split string by “ “ : Combine with the C++ Folder string manipulation file

 <span style="font-size: 20.0;">
     #include <sstream>
vector<
 </span> <span style="font-size: 20.0;">
     *string*
 </span> <span style="font-size: 20.0;">
     > splitByWhitespace(
 </span> <span style="font-size: 20.0;">
     *const*
 </span>  <span style="font-size: 20.0;">
     *string&*
 </span> <span style="font-size: 20.0;">
      str) {
    vector<
 </span> <span style="font-size: 20.0;">
     *string*
 </span> <span style="font-size: 20.0;">
     > tokens;
    
 </span> <span style="font-size: 20.0;">
     *istringstream*
 </span> <span style="font-size: 20.0;">
      iss(str);
    
 </span> <span style="font-size: 20.0;">
     *string*
 </span> <span style="font-size: 20.0;">
      token;
    while (iss >> token) {
 </span> <span style="font-size: 20.0;">
      *// Reads words separated by whitespace*
 </span> <span style="font-size: 20.0;">
     
        tokens.push_back(token);
    }
    return tokens;
}

 </span>