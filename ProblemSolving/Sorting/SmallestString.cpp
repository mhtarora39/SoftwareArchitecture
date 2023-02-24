#include <iostream>
#include <vector>
#include <string>

void merge_string(std::vector<std::string> &array, int start, int part, int end)
{
    int left = start;
    int right = part + 1;
    std::vector<std::string> tmp_array;
    while (left < right && right <= end)
    {
        if (array[left] + array[left + 1] < array[right] + array[left])
        {
            tmp_array.push_back(array[right]);
            right++;
        }
        else
        {
            left++;
            tmp_array.push_back(array[right]);
        }
    }


}

std::string part_strings(std::vector<std::string> &array, int start, int end)
{

    if (start >= end)
    {
        return "";
    }
    int mid = (start + end) / 2;

    part_strings(array, start, mid);
    part_strings(array, mid + 1, end);
    merge_string(array, start, mid, end);
    std::string tmp = "";
    for(auto str : array) {
        tmp += str;
    }
    return tmp;
}

int main()
{
    std::vector<std::string> array = {"a", "ab", "aaa"};
    std::cout << " answer should be 'aaaaab'" << part_strings(array,0,array.size()-1) << std::endl;
     
}