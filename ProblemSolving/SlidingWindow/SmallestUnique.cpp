#include <iostream>
#include <string>

std::string smallestWindow(std::string str){
    int counter[256] = {0};
    int counter_2[256] = {0};
    int total_unique = 0;
    // Total count of each char
    for(const auto& ch : str) {
        if(counter[ch] == 0 ) {
            total_unique++;
        }
        counter[ch]++;
    }
    // Now moving left right_idx
    int unique = 0;
    int left = 0;
    int min_len = str.size();
    int start_idx = 0;
    for(int right_idx=0; right_idx < str.size(); right_idx++) {
        char ch = str[right_idx];
        if(counter_2[ch] == 0) {
            unique++;
        }
        counter_2[ch]++;
        if(unique == total_unique) {
            while(counter_2[ch] > 1) {
                left++;
                if(counter_2[ch] > 1) {
                  counter_2[ch]--;
                }
            }

            if(right_idx - left  + 1 < min_len) {
               min_len = right_idx - left  + 1;
               start_idx = left; 
            }  
        }


    }
    return str.substr(start_idx,min_len); 
}

// Driver code
int main()
{
    std::string str = "aabcbcdbca";
    std::cout << "Smallest window containing all distinct"
            " characters is: "
         << smallestWindow(str) << " == dbca" << std::endl;
    return 0;
}

