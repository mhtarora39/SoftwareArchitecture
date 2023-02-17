#include <vector>
#include <algorithm>
#include <climits>
#include <iostream>

std::pair<int, int> minDifference(std::vector<int> arr1, std::vector<int> arr2)
{
    std::sort(arr1.begin(), arr1.end());
    std::sort(arr2.begin(), arr2.end());
    int curr_idx = 0;
    // ToDo Comeback
    int last_eval_arr1 = arr1[0];
    int last_eval_arr2 = arr2[0];
    std::pair<int, int> result;
    int min_diff = INT_MAX;
    int i = 0;
    for (i = 0; i < arr1.size() && curr_idx < arr2.size();)
    {
        int ele1 = arr1[i];
        int ele2 = arr2[curr_idx];
        if (ele1 < ele2)
        {
            if (min_diff > std::abs(last_eval_arr1 - ele2))
            {
                last_eval_arr2 = ele2;
                result = std::pair<int, int>(last_eval_arr1, ele2);
                min_diff = std::abs(last_eval_arr1 - ele2);
            }
            i++;
        }
        else
        {
            if (min_diff > std::abs(last_eval_arr2 - ele1))
            {
                last_eval_arr1 = ele1;
                result = std::pair<int, int>(ele1, last_eval_arr2);
                min_diff = std::abs(last_eval_arr2 - ele1);
            }
            curr_idx++;
        }
        
    }

    if (i < arr1.size())
    {
        if (min_diff > std::abs(arr2[curr_idx - 1] - arr1[i]))
        {
            result = std::pair<int, int>(arr1[i], arr2[curr_idx - 1]);
        }
    }

    if (curr_idx < arr2.size())
    {
        if (min_diff > std::abs(arr2[curr_idx] - arr1[i - 1]))
        {
            result = std::pair<int, int>(arr1[i - 1], arr2[curr_idx]);
        }
    }
    return result;
}

int main() {
    auto res = minDifference({23, 5, 10, 17, 30},{26, 134, 135, 14, 19});
    std::cout << " Result : " << res.first << " , " << res.second << std::endl; 
}