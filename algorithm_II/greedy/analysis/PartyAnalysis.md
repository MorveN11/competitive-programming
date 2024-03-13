# Coco's theme party Analysis - Manuel Morales

### Greedy Choice:
- The greedy choice in this problem is to pair the guests with the highest and lowest levels of happiness together. This is done by sorting the happiness levels and pairing adjacent guests accordingly.
- The greedy choice is explain how the algorithm works and how it makes the greedy choice.

### Optimal Substructure:
- The optimal substructure in this problem lies in the fact that maximizing the enjoyment of the party can be achieved by maximizing the difference in happiness levels between adjacent guests. This substructure allows us to make the greedy choice of pairing guests with the highest and lowest happiness levels together.
- The optimal substructure is explain how the problem can be broken down into smaller subproblems and how the greedy choice is made based on these subproblems.

### Time Complexity:
- Sorting the happiness levels takes O(n log n) time, where n is the number of guests. The rest of the operations, such as creating the minors and majors vectors and computing the maximum enjoyment, can be done in O(n) time. Therefore, the overall time complexity of the solution is O(n log n).
