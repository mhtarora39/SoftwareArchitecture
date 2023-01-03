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
    int diff    = main_str.size();
    int from    = 0;
    char first  = '';
    for(int i = 0; i < main_str.size();i++) {
        auto  ch = main_str[i];
        if(char_count.find(ch) != char_count.end()) {
            if(char_count[ch] > 0) {
              char_count[ch]--;
              max_pos = i;
            }
            else if(min_pos == -1) {
                min_pos = i;
            }
            else
            {
                // Here i will check if till what i can increase min_pos closer to current
                // Pos. Which include all the chars.
                // First i will pop first char.
                // foffxonnxx 4,5
                // fizzbuzz fuzz
                //
                int tmp_min = min_pos; 
                while (tmp_min < i)
                {
                    auto tmp_char = main_str[tmp_min];
                    if ((char_count.find(tmp_char) != char_count.end() &&
                         char_count[tmp_char] == 0 && char_count[tmp_char] == ch) ||
                        (char_count.find(tmp_char) == char_count.end()))
                    {
                        tmp_min++;
                        if(i - tmp_min < diff) {
                           diff = i - tmp_min;
                           min_pos = tmp_min;
                           max_pos = i;
                        }

                    }
                    else
                    {
                        break;
                    }
                }
                // check that char count == 0 and this is same as current char
                // min++;
                // if char doesn't exist
                // min++
                // else
                // Store the window size and index if that is minimum
                // Break
            }
        }
    }
    //Count
    //Postion-> o - len() => degree pf movement
    //This is order agnostic
    // Let's search for Where to start ?
    // oXX -> Min 4 , 9
    //            1,  5
    ////////////////////////////
    // foffxonnxx 4,5 //////////
    // min_pos -> char , index 
    // max_pos -> char , index 
    // offxo  -> o     
}