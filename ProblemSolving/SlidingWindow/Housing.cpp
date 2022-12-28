#include <iostream>
#include <vector>
 

std::vector<int> getSum(std::vector<int> array,int k) {
    int left = 0;
    int right = 0;
    int sum  = 0;
    for(int i = 0; i < array.size();i++) {
        sum = sum + array[i];
        right = i;
        left = 0;
        while(sum > k and left <= i) {
           sum = sum - array[left];
           if(sum == k) {
              return {left+1 , right};
           }
           left++;  
        }
    }
    return {}; 
}

int main() {
    auto ans = getSum({1,3,2,1,4,1,3,2,1,1,2},7);
    std::cout << " Left " << ans[0] << " right " << ans[1] << std::endl;
}