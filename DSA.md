## Useful tips -

* We can reduce time complexity to an extent keeping the same space complexity. But for further optimisisations, like for writing prod level code, we need to understand that in order to reduce TC, we need to increase 
the SC.
* For DP - there are two criteria to check -
  - whether optimal solution of the problem is the summation of optimal solutions of subproblems.
  - AND whether the problem has overlapping subproblems.
* Moreover, to solve DP problems -
  - First write recursive equation.
  - Solve through recursion.
  - Top-bottom memoization -
    - Recursion -> Top-Bottom memo : Introduce a dp array of n+1 length. Initialize with -1. Instead of directly returning the recursion output, store it in dp[i] and return this value whenever next time it is called.
  - Bottom up tabulation.
    -  Introduce a dp array of n+1 length. Initialize it according to the context. And keep on building the arr through recursive relation. Return the last element of dp arr.
  - Fine tuning - To further improve space complexity, introduce variables to replace arrays.
    
