# Coco's birthday Analysis - Manuel Morales

### Greedy Choice:
- The greedy choice in this problem is to prioritize letting guests with higher happiness levels in first, as this maximizes the overall enjoyment of the party. In addition, if a guest at the end of the line has been waiting a long time (i.e., has a happiness level low or equal to 0 about to leave), it may be beneficial to let them in earlier to prevent their happiness from decreasing further or to prevent them from leaving the party.

### Optimal Substructure:
- The optimal substructure property is satisfied because if I can find out how to optimally enter an L1 based on happiness, the global optimal solution will contain the optimal solution for a (G - L1) and the optimal solution of an L1.

### Time Complexity:
- Sorting the happiness levels takes O(n log n) time, where n is the number of guests. After sorting, iterating through the guests and allowing them to enter the party takes linear time O(n). Therefore, the overall time complexity of the solution is dominated by the sorting step and is O(n log n).
