#include <iostream>
#include <vector>
#include <string>

void merge_string(std::vector<std::string> &array, int start, int part, int end)
{
    int left = start;
    int right = part + 1;
    std::vector<std::string> tmp_array;
    while (left <= part && right <= end)
    {
        if (array[left] + array[right] < array[right] + array[left])
        {
            tmp_array.push_back(array[left]);
            left++;
        }
        else
        {
            tmp_array.push_back(array[right]);
            right++;
        }
    }

    while (left <= part)
    {
        tmp_array.push_back(array[left++]);
    }

    while (right <= end)
    {
        tmp_array.push_back(array[right++]);
    }
    for(int i = 0; i < tmp_array.size(); i++) {
        array[i + start] = tmp_array[i];
    }

}

void part_strings(std::vector<std::string> &array, int start, int end)
{

    if (start >= end)
    {
        return ;
    }
    int mid = (start + end) / 2;

    part_strings(array, start, mid);
    part_strings(array, mid + 1, end);
    merge_string(array, start, mid, end);
}
    

int main()
{
    std::vector<std::string> array = {"a", "ab", "aaa"};
    std::string tmp = "";
    part_strings(array,0,array.size() - 1);
    for(auto str: array) {
        tmp += str;
    }
    std::cout << " answer should be 'aaaaab' but result is : " << tmp << std::endl;
}