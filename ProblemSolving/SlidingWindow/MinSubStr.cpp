#include <string>
#include <unordered_map>
#include <limits.h>
#include <iostream>


std::string MinSubStr(const std::string& main_str,const std::string& to_search) {
    std::unordered_map<char,int> pattern_count , frequency_count;
    int total_count = to_search.size();
    int cnt = 0;
    int total_letters = 0;
    int start_idx = 0;
    int from = 0;
    int min_len = INT_MAX;

    // As we can ignore pattern sequence so making map
    for(auto& ch : to_search) {
        pattern_count[ch]++;
    }

    // For each pattern algorithm we always contract from one side and expend from other side.
    for(int i = 0; i <  main_str.size(); i++) {
        char ch = main_str[i]; 
        frequency_count[ch]++;
        if (pattern_count.find(ch) != pattern_count.end() && frequency_count[ch] <= pattern_count[ch])
        {
            cnt++;
        }
        // All letters are found.
        if(cnt == total_letters) {
           // Now we will start all the extra chars from frequency count.
           // Based On Below Conditions.
           // 1) Chr is not present in pattern.
           // 2) Chr count is more then pattern count in frequency map.  
           auto ch_tmp = main_str[start_idx];
           while (pattern_count.find(ch_tmp) != pattern_count.end() ||
                  frequency_count[ch_tmp] > pattern_count[ch_tmp])
           {
               frequency_count[ch_tmp]--;
               ch_tmp = main_str[++start_idx];
           }

           if(i - start_idx < min_len) {
                min_len = i - start_idx;
                from = start_idx;
           }

        } 
    }
    if(from == -1) {
        return "No Window Found!";
    }
    else {
        return main_str.substr(from,min_len);
    }
}

int main() {
    std::cout << MinSubStr(" Helolpxoooxlmn","olx") << " == oxl \n"; 
}




    