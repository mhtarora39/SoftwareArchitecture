#include <iostream>


void replace(std::string src, std::string from , std::string to) {

//Hi My Name is Mohit  -->  Calculate new space
int found = 0;

// Calculate How many sub string are there
for(int i = 0; i < src.size(); i++) {
    if(src.substr(i, from.size()) == from) {
       found++;
    }
}

int new_len   = src.size() + found*(abs(to.size() - from.size())) + 1;

int new_index = new_index -1;

for(int i = src.size() -1 ; i >=0; i--) {
    if(src.substr(i, from.size()) == from) {
        for(int j = to.size()-1; j >= 0 ; j--) {
            src[i-j] = to[j];
        }
        new_index = new_index - to.size();
    }
    else {
       src[new_index] = src[i];
       new_index--; 
    }
}

}


int main() {
    return 1;
}