# String parsing/ formatting / input tricks



# Split string by whitespaces
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
![9056657E-1084-43E5-868F-76E9B889FDE4](images/9056657E-1084-43E5-868F-76E9B889FDE4.png)
![12954FA1-4E24-41C5-829E-A49AEBF8B64B](images/12954FA1-4E24-41C5-829E-A49AEBF8B64B.png)
![C6EF3604-12F4-4AC8-86F4-45AB2C182D51](images/C6EF3604-12F4-4AC8-86F4-45AB2C182D51.png)

# Split string by custom delimiter:
#include <bits/stdc++.h>
#include <sstream>
using namespace std;

int main() {
    *string* input;
    vector<*string*> output;
    getline(cin, input);
    *istringstream* iss(input);
    *string* token;
    while(getline(iss, token, ',')){
        output.push_back(token);
    }
    for(auto s : output){
        cout << s << "\n";
    }
    return 0;
}
![10C714F2-4945-473C-9B2B-65ECECB6179D](images/10C714F2-4945-473C-9B2B-65ECECB6179D.png)
 <span style="font-size: 26.0;">
     **Hence,** 

 </span>#include <bits/stdc++.h>
#include <sstream>
using namespace std;

int main() {
    *string* input;
    vector<*string*> output;
    getline(cin, input);
    *istringstream* iss(input);
    *string* token;

    while(iss >> token){
        output.push_back(token);
    }
    
    for(auto s : output){
        cout << s << "\n";
    }
    return 0;
}


 <span style="font-size: 26.0;">
     **Split string by multiple delimiters**
 </span>
#include <bits/stdc++.h>
#include <regex>
using namespace std;

int main() {
    string input;
    getline(cin, input);

    // Regex: split by , ; : or space
    regex re("[,;: ]+");  // the + means "one or more of these"
    sregex_token_iterator it(input.begin(), input.end(), re, -1);
    sregex_token_iterator end;

    for (; it != end; ++it) {
        if (!it->str().empty()) // optional: avoid empty tokens
            cout << *it << "\n";
    }

    return 0;
}


 <span style="font-size: 26.0;">
     **Common String to Number / Number to String Conversions**

 </span>![86C100AB-EEE5-4F78-AA39-BEE0B8F8D722](images/86C100AB-EEE5-4F78-AA39-BEE0B8F8D722.png)
![61974815-DFAC-4DDB-B6D3-409E6FAD3615](images/61974815-DFAC-4DDB-B6D3-409E6FAD3615.png)
![D128E789-7A80-47C7-A36A-2F8FD4C68921](images/D128E789-7A80-47C7-A36A-2F8FD4C68921.png)

![FC53FCED-5E64-4AC8-97D6-C048272E5D64](images/FC53FCED-5E64-4AC8-97D6-C048272E5D64.png)
![6CE64C92-521B-46A9-B52C-1D7B1F80BCC4](images/6CE64C92-521B-46A9-B52C-1D7B1F80BCC4.png)

![26DD6E64-8808-4B2B-AAE6-DEC0347122CC](images/26DD6E64-8808-4B2B-AAE6-DEC0347122CC.png)
![EA812FA3-DB30-44B0-85A2-59906CCAACEE](images/EA812FA3-DB30-44B0-85A2-59906CCAACEE.png)

![14CBF277-503C-4E12-8ABD-CAFFC0077EA6](images/14CBF277-503C-4E12-8ABD-CAFFC0077EA6.png)
![2A226828-82C1-44DD-A992-7CFE215D86B4](images/2A226828-82C1-44DD-A992-7CFE215D86B4.png)
![60820ACB-0F23-4AF2-BE7B-89642C066CEB](images/60820ACB-0F23-4AF2-BE7B-89642C066CEB.png)
![93547A5E-7551-4F31-A8A1-4162F3970F31](images/93547A5E-7551-4F31-A8A1-4162F3970F31.png)
![28A9C606-7F36-4037-983B-FD5660E8AF7C](images/28A9C606-7F36-4037-983B-FD5660E8AF7C.png)
![BCF38E11-2266-487E-90B9-AAB16D7982DA](images/BCF38E11-2266-487E-90B9-AAB16D7982DA.png)
![12D60FAC-1D84-4716-A87B-4C729595ABCC](images/12D60FAC-1D84-4716-A87B-4C729595ABCC.png)
