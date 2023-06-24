class Solution:
    def getTreeRight(self,root, answer):
        if root == None:
            return None
        if root.left == None and root.right == None:
            return None
        
        if root.right: 
            new_root = self.getTreeRight(root.right,answer)
            head = root
        elif root.left:
            new_root = self.getTreeRight(root.left,answer)
            head = root
            
        if new_root:    
            answer.append(new_root.data)
        return head
        
    def getLeafs(self,root, answer):
        
        if root == None:
            return None
        
        
        
        if root.left == None and root.right == None:
            answer.append(root.data)
            
        if root.left:
            self.getLeafs(root.left,answer)
        
            
        
        if root.right: 
            self.getLeafs(root.right,answer)
        
        
        return
        
        
        
    def printBoundaryView(self, root):
        # Code here
        #  Left arm of tree , right arm of tree and leaf
        answer = []
        answer.append(root.data)
        if (root.left == None and root.right==None):
            return answer
            
        if root.left:
            first = True
            nodes = [root.left]
            tmp_nodes = []
            while(len(nodes) > 0):
                node = nodes.pop(0)

                if (first and (node.left != None or node.right!= None)):
                    answer.append(node.data)
                    first = False
                
        
                if node.left:
                    tmp_nodes.append(node.left)
                
                elif node.right:
                    tmp_nodes.append(node.right)
                
                if len(nodes) == 0:
                    first = True
                    nodes = tmp_nodes
                    tmp_nodes = []
      
        #print(answer)
        self.getLeafs(root, answer)
        #print(answer)
        if  root.right:
            self.getTreeRight(root, answer)
            
        return answer
#{ 
 # Driver Code Starts
#Initial Template for Python 3

# function should return a list containing the boundary view of the binary tree
#{ 
#  Driver Code Starts

import sys
sys.setrecursionlimit(100000)
#Contributed by Sudarshan Sharma
from collections import deque
# Tree Node
class Node:
    def __init__(self, val):
        self.right = None
        self.data = val
        self.left = None

# Function to Build Tree   
def buildTree(s):
    #Corner Case
    if(len(s)==0 or s[0]=="N"):           
        return None
        
    # Creating list of strings from input 
    # string after spliting by space
    ip=list(map(str,s.split()))
    
    # Create the root of the tree
    root=Node(int(ip[0]))                     
    size=0
    q=deque()
    
    # Push the root to the queue
    q.append(root)                            
    size=size+1 
    
    # Starting from the second element
    i=1                                       
    while(size>0 and i<len(ip)):
        # Get and remove the front of the queue
        currNode=q[0]
        q.popleft()
        size=size-1
        
        # Get the current node's value from the string
        currVal=ip[i]
        
        # If the left child is not null
        if(currVal!="N"):
            
            # Create the left child for the current node
            currNode.left=Node(int(currVal))
            
            # Push it to the queue
            q.append(currNode.left)
            size=size+1
        # For the right child
        i=i+1
        if(i>=len(ip)):
            break
        currVal=ip[i]
        
        # If the right child is not null
        if(currVal!="N"):
            
            # Create the right child for the current node
            currNode.right=Node(int(currVal))
            
            # Push it to the queue
            q.append(currNode.right)
            size=size+1
        i=i+1
    return root
    
    
if __name__=="__main__":
    t=int(input())
    for _ in range(0,t):
        s=input()
        root=buildTree(s)
        obj = Solution()
        res = obj.printBoundaryView(root)
        for i in res:
            print (i, end = " ")
        print('')
# } Driver Code Ends