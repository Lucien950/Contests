# Recipe for Memorization

```bash
💡 NAME OF THE GAME IS TO REDUCE RECOMPUTATION
```

1. Make it work recursively
   - Helps to visualize the problem as a tree
   - TESTING
2. Make it efficient
   - Cut the branches which are repeating computation
   - Add DP object, hard add some base cases if necessary and not covered by the function
   - Store returns values in the DP object
   - Check for answer in DP object, and only calculate if the answer is not already in the DP

#CanSum, HowSum, BestSum Models
![image](https://user-images.githubusercontent.com/20777515/131700146-9d20e7d5-1823-4e5c-a996-0606d719f417.png)

#Testing DP
If you put print values in the DP object check, 

```python
 if value in dp:
     print("saved time")
     return False
```
you can tell where you saved time