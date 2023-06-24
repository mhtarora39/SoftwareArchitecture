## [Counting Coin](./counting_coins.cpp)

Given an integer array of coins[ ] of size N representing different types of currency and an integer sum, The task is to find the number of ways to make sum by using different combinations from coins[].  
Note: Assume that you have an infinite supply of each type of coin.

## Input: 
sum = 4, coins[] = {1,2,3}, 
Output: 4
## Explanation: 
there are four solutions: {1, 1, 1, 1}, {1, 1, 2}, {2, 2}, {1, 3}.


## [Count Ways To Reach The N-th Stairs](./count_steps.py)

A child is running up a staircase with n steps and can hop either 1 step, 2 steps, or 3 steps at a time. Implement a method to count how many possible ways the child can run up the stairs.

Input : 3
Output : 4
### Explanation:
Below are the four ways </br>
 1 step + 1 step + 1 step</br>
 1 step + 2 step</br>
 2 step + 1 step</br>
 3 step</br>

## [Min Deletion Required To Palindrome](./min_del_palindrome.py)
Given a string of size ‘n’. The task is to remove or delete the minimum number of characters from the string so that the resultant string is a palindrome. 

Note: The order of characters should be maintained. 


### Examples : 
</br>
Input : aebcbda
</br>
Output : 2
</br>
Remove characters 'e' and 'd'
</br>
Resultant string will be 'abcba'
</br>
which is a palindromic string

Input : geeksforgeeks
Output : 8


[max-sum-without-adjacents](maximum_sum_no_adj.py): Given an array Arr of size N containing positive integers. Find the maximum sum of a subsequence such that no two numbers in the sequence should be adjacent in the array.

### Example 1:
</br>
Input:
</br>N = 6
</br>Arr[] = {5, 5, 10, 100, 10, 5}
</br>Output: 110
</br>Explanation: If you take indices 0, 3
</br>and 5, then Arr[0]+Arr[3]+Arr[5] =
</br>5+100+5 = 110.
</br>Example 2:
</br>
</br>Input:
</br>N = 4
</br>Arr[] = {3, 2, 7, 10}
</br>Output: 13
</br>Explanation: 3 and 10 forms a non
</br>continuous  subsequence with maximum
</br>sum.
