#include <string>
#include <unordered_map>

int MinSubStr(const std::string& main_str,const std::string& to_search) {
    std::unordered_map<char,int> char_count;
    int total_count = to_search.size();
    for(auto& ch : to_search) {
        char_count[ch]++;
    }
    int min_pos = -1;
    int max_pos = 0;
    char first  = "";
    for(int i = 0; i < main_str.size();i++) {
        auto  ch = main_str[i];
        if(char_count.find(ch) != char_count.end()) {
            if(min_pos == -1) {
                min_pos = i;
                first   = ch;
            }
            total_count--;
            if(total_count == 0) {
                max_pos = i;
            }
        }
    } 
    
    
}