#include <iostream>
#include <string>
#include <unordered_map>

int findUniqueSubStr(const std::string& string) {
   std::unordered_map<char,int> char_to_idx;
   int max_len = 0;
   int curr_len = 0;
   //MohitMohabcde;
   //abbbbcd 
   for(int i =0;i < string.size();i++) {
       
        if(char_to_idx.find(string[i]) != char_to_idx.end()) {
           if(max_len < curr_len) {
            max_len = curr_len;
           }
           curr_len = i - char_to_idx[string[i]];
        }
        else {
            curr_len++;
        }
        char_to_idx[string[i]] = i;
   }
   max_len = std::max(curr_len,max_len);
   return max_len;
}

int main() {
    std::cout << "sending abbbbbcd " << findUniqueSubStr("abbbbbcd") << " == 3" << std::endl;
    std::cout << "sending MohitMohKUR " << findUniqueSubStr("MohitMohKUR") << " == 8" << std::endl;
    std::cout << "sending abcabeb " << findUniqueSubStr("abcabeb") << " == 4" << std::endl;
}