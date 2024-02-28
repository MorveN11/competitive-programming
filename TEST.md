# Test Algorithm - Manuel Morales

Q1 Given the following recursive code:

Solution a)
```java
private static int function(int n, int [] dp) {
  if (n == 0) 
  {
    return 0;
  }

  if (n == 1 || n == 2)
  {
    return 1;
  }

  if (dp[n] != 0) 
  {
    return dp[n];
  }

  dp[n] = function(n - 1, dp) + function(n - 2, dp) + function(n - 3, dp);

  return dp[n];
}
```

Solution b)
This code need the base case after adding dynamic programming. because when we execute this code for first time this dp doesnt have the value of dp[1] and dp[2]

Q2 if we can solve a problem by combining the solutions of its subproblems, does that mean that we can solve with a DP algorithm?

Yes that is the definition of a DP algorithm.
because with this subproblems we can memoizar all the posibles results of any algorithm

Q3 In the Edit Distance algorithm when we do a insertion operation, why do we need to look at the Edit-Distance of the previous character position of the second String?

E(i, j) = E(i, j - 1) + 1

Because we need to know the previous character to know the distance between the two characters

Q4 - Analisis
a) Identify the problem in general Terms
We recieve two 1 array of N leght like this
4
1 12 5 31
And we need to minimun of amount of gifts we need to move around the gifts to make the arranged correctly.
b) Analyse the problem based on sub-problems and find the formula
This problem is similar and we are able to apply the Edit Distance algorithm that is a DP bottom up algorithm, the subproblem is to find the distance between the two characters and the formula
E(i, j) = min {E(i - 1, j) + 1, E(i, j - 1) + 1, E(i - 1, j - 1) + val}
c) Identify were the overlap of sub-problems occurs
The overlap of sub-problems occurs when we need to move the gifts to the correct position
d) Implement the solution to the problem using DP bottom up
Test.cpp file
