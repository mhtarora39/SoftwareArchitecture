#include <iostream>
#include <vector>

void generateSubsequence(std::string in_str, std::string out_str, std::vector<std::string>& result) {
    if(in_str.size() == 0) {
        result.push_back(out_str);
        return;
    }
    char ch = in_str[0];
    generateSubsequence(in_str.substr(1), out_str + ch,result);
    generateSubsequence(in_str.substr(1), out_str,result);

}


int main() {
    std::vector<std::string> results;
    generateSubsequence("ab","",results);
    for(auto& res : results) {
        std::cout << res << ",";
    }
    
}