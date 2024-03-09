# Coco's birthday Analysis - Manuel Morales

### Greedy Choice:
- The greedy choice in this problem is to prioritize letting in guests with higher happiness levels first. This is achieved by sorting the happiness levels in descending order and then allowing guests to enter the party based on their happiness level and their position in the line.

### Optimal Substructure:
- The optimal substructure lies in maximizing the number of people entering the party by selecting the guests with the highest happiness levels to enter first. Additionally, the algorithm considers the impact of other guests entering before a particular guest, as this can affect their happiness level. Therefore, by maximizing the number of guests with positive happiness levels allowed into the party, we achieve the optimal substructure.

### Time Complexity:
- Sorting the happiness levels takes O(n log n) time, where n is the number of guests. After sorting, iterating through the guests and allowing them to enter the party takes linear time O(n). Therefore, the overall time complexity of the solution is dominated by the sorting step and is O(n log n).
