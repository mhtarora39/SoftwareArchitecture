
"""
Count Ways To Reach The N-th Stairs
A child is running up a staircase with n steps and can hop either 1 step, 2 steps, or 3 steps at a time. Implement a method to count how many possible ways the child can run up the stairs.

Input : 3 Output : 4

Explanation:
Below are the four ways
1 step + 1 step + 1 step
1 step + 2 step
2 step + 1 step
3 step
"""

## 1,2,3, 4 
def count_steps(target,curr_count, steps_array):
    if target == 0:
        return 1
    
    if target < 0:
        return 0
    total = 0
    
    for step in steps_array:
        total += count_steps(target - step,curr_count+1,steps_array) 
        
    return total
if __name__ == "__main__":
    print(f"Total should be 4 == {count_steps(3,0,[1,2,3])} ") 



