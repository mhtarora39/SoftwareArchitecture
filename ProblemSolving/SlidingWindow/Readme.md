[Housing](Housing.cpp):
Along one side of a road there is a sequence of vacant
plots of land. Each plot has a different area (non-zero).
So,The area of the sequence A[1] , A[2] .... A[N]

You want to buy K acres of land to build a house. You want
to find all segments of continuous plots (i.e., a subsection
in the sequence) of whose sum is exactly K.

[Unique Substring](UniqueSubStr.cpp):</br>
Given a string s, find the length of the longest 
substring
 without repeating characters.
 Example 1:

Input: s = "abcabcbb"</br>
Output: 3</br>
Explanation: The answer is "abc", with</br> the length of 3.</br>
Example 2:</br>
</br>
Input: s = "bbbbb"
</br>
Output: 1
</br>
Explanation: The answer is "b", with 
</br>
the length of 1.
</br>
Example 3:
</br>
Input: s = "pwwkew"
</br>
Output: 3
</br>
Explanation: The answer is "wke", with 
</br>
the length of 3.
</br>
Notice that the answer must be a 
</br>
substring, "pwke" is a subsequence and not a substring.
</br> 

Constraints:
</br>
0 <= s.length <= 5 * 104
</br>
s consists of English letters, digits, 
</br>
symbols and spaces.

[Minimum Window Substring](MinSubStr.cpp): <p> Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "". </p>
</br>

The testcases will be generated such that the answer is unique.

 

Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
</b>Output: "BANC"
</b>Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
</b>Example 2:

</br>Input: s = "a", t = "a"
</br>Output: "a"
</br>Explanation: The entire string s is the minimum window.
</br>Example 3:

</br>Input: s = "a", t = "aa"
</br>Output: ""
</br>Explanation: Both 'a's from t must be included in the window.
</br>Since the largest window of s only has one 'a', return empty string.
 

</br>Constraints:

</br>m == s.length
</br>n == t.length
</br>1 <= m, n <= 105
</br>s and t consist of uppercase and lowercase English letters.
 

</br>Follow up: Could you find an algorithm that runs in O(m + n) time?
