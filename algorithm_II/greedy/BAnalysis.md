# B Problem Analysis - Manuel Morales

### Identify the greedy choice:
In this problem, the greedy choice is to select the three most expensive items in each iteration to obtain the maximum possible discount. By always selecting the most expensive items, the discount obtained is maximized.

### Identify the optimal substructure:
The optimal substructure in this problem lies in the fact that the optimal solution for the overall problem can be built from optimal solutions to smaller subproblems. This is reflected in the approach of selecting the three most expensive items in each iteration to maximize the total discount.

### Proof of your greedy algorithm using "greedy stays ahead":
To prove the correctness of my greedy algorithm, I will use the "greedy stays ahead" principle. Let's define the measure of the greedy solution as the sum of discounts obtained in each iteration, denoted as m(G). Similarly, let's define the measure of the optimal solution as the sum of discounts obtained in each iteration, denoted as m(O).

1. **Define your solution**: 
   - Let G be the solution produced by my greedy algorithm, and O be the solution produced by the optimal algorithm.

2. **Define a measure**: 
   - Let m(G) be the sum of discounts obtained by the greedy solution, and let m(O) be the sum of discounts obtained by the optimal solution.

3. **Prove greedy stays ahead**: 
   - I will prove that m(G) ≥ m(O).
   - Suppose, for the sake of contradiction, that m(G) < m(O). This implies that the greedy solution produces less total discount than the optimal solution.
   - However, since my greedy algorithm always selects the three most expensive items in each iteration, it guarantees that the discount obtained in each iteration is maximized. Therefore, it is impossible for the optimal solution to produce a greater discount in any iteration.
   - Thus, we have reached a contradiction, demonstrating that m(G) ≥ m(O).

4. **Prove optimality**: 
   - Since greedy stays ahead and we have shown that m(G) ≥ m(O), it follows that the greedy algorithm produces the optimal solution.

### Time complexity of your solution:
The time complexity of my solution is O(n log n), where n is the number of items Lindsay is buying. This complexity arises from the sorting of the prices of the items, followed by a linear iteration over the sorted prices. Therefore, the overall time complexity is dominated by the sorting step.
