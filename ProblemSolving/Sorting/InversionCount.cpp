#include<iostream>
#include<vector> 

void partition(std::vector<int>& arr, int start , int mid ,int end,int &inversion_count) {
    int right = mid+1;
    int left = start;
    //Here Assumption is that both the vectors are sorted
    //We can't do in place swapping as this will disturb the 
    //sorting of two partition
    std::vector<int> tmp_array;  
    while(start <= mid && right <= end) {
        if(arr[start] >=  arr[right]) {
            inversion_count += mid - start + 1;
            tmp_array.push_back(arr[right]);
            right++;
        }
        else {
            tmp_array.push_back(arr[start]);
            start++;
        }    
    }
    while(start <= mid) {
        tmp_array.push_back(arr[start]);
        start++;
    }
    while(right <= end) {
        tmp_array.push_back(arr[right]);
        right++;
    }
    int j = 0;
    for(int i = left;i <= end;i++) {
        arr[i] = tmp_array[j];
        j++;
    }

}

int inversion_count(std::vector<int>& arr, int start, int end , int& count) {
    if(end - start < 1) {
        return 0;
    }
    int mid = (start + end) / 2;
    inversion_count(arr,start,mid,count);    
    inversion_count(arr,mid+1,end,count);
    partition(arr,start, mid,end,count);
    return count;
}

int main() {
    std::vector<int> arr = {0,5,2,3,1};

    int count = 0; 
    inversion_count(arr, 0, arr.size()-1,count);
    std::cout << " Count should be  5 == " << count << std::endl;

    arr = {3, 2, 1};
    count = 0;
    inversion_count(arr, 0, arr.size()-1,count);
    std::cout << " Count should be  3 == " << count << std::endl;
    arr = {6, 3, 5 ,2, 7};
    count = 0;
    inversion_count(arr, 0, arr.size()-1,count);
    std::cout << " Count should be  5 == " << count << std::endl;
     
}



