### [Boundary Traversal of binary tree](./Bounderytree.py) 
</br>Given a Binary Tree, find its Boundary Traversal. The traversal should be in the following order: 

</br>Left boundary nodes: defined as the path from the root to the left-most node ie- the leaf node you could reach when you always travel preferring the left subtree over the right subtree. 
</br>Leaf nodes: All the leaf nodes except for the ones that are part of left or right boundary.
</br>Reverse right boundary nodes: defined as the path from the right-most node to the root. The right-most node is the leaf node you could reach when you always travel preferring the right subtree over the left subtree. Exclude the root from this as it was already included in the traversal of left boundary nodes.
</br>Note: If the root doesn't have a left subtree or right subtree, then the root itself is the left or right boundary. 
</br>
### Example 1:

Input:
```

        1 
      /   \
     2     3  
    / \   / \ 
   4   5 6   7
      / \
     8   9
   
Output: 1 2 4 8 9 6 7 3
```
