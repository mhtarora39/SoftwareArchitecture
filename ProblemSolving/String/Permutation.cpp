#include <vector>
#include <iostream>

std::string Permute(const std::string& s, const std::string& o ,std::vector <std::string> & r ) {

    if(s.size() == 0) { r.push_back(o); return ""; }
    //if(s.size() == 1) { return s;}

    auto ch = s[0];
    Permute(s.substr(1),o+ch,r);
    Permute(s.substr(1),o,r);
    
    return s;
}

int main() {
    std::string str = "abc";
    std::vector<std::string> res;
    Permute(str,"",res);
    for(auto& r : res) {
        std::cout << " Res = " << r << std::endl;
    }
}