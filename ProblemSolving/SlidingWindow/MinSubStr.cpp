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
        total_letters++;
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
        auto ch_tmp = main_str[start_idx];
        bool pattern_contracted = false;
        // We are checking here if all the ch
        if(cnt ==  total_letters) {
           // Now we will start all the extra chars from frequency count.
           // Based On Below Conditions.
           // 1) Chr is not present in pattern.
           // 2) Chr count is more then pattern count in frequency map.  
           while (pattern_count.find(ch_tmp) == pattern_count.end() ||
                  frequency_count[ch_tmp] > pattern_count[ch_tmp])
           {
                pattern_contracted =true;
                frequency_count[ch_tmp]--;
                ch_tmp = main_str[++start_idx];
           }

            if(i - start_idx + 1 < min_len) {
                min_len = i - start_idx + 1;
                from = start_idx;
            }
        }
        // if(pattern_contracted) {
        //     cnt--;
        //     frequency_count[ch_tmp]--;
        // }
    }
    if(from == -1) {
        return "No Window Found!";
    }
    else {
        return main_str.substr(from,min_len);
    }
}

int main() {               //          3
    std::cout << MinSubStr("iikikkj","iikj") << " == ikikkj \n"; 
    std::cout << MinSubStr("hello_world","llo") << " == llo \n";
    std::cout << MinSubStr("fizzbuzz","fuzz") << " == fizzbu \n";
    std::cout << MinSubStr("ADOBECODEBANC","ABC") << " == BANC \n";
}




    