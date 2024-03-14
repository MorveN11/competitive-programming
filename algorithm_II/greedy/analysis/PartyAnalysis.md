# Coco's theme party Analysis - Manuel Morales

### Greedy Choice:
- Tomar un invitado del inicio y uno del final cuando sea posible de mi lista de invitados ordenados ascendentemente.

### Optimal Substructure:
-  SO = Solucion Optima | G = Global | L = Local 1
-  SO(G) = SO(L1) U SO(G - L1)
-  Se cumple con la propiedad de subestructura optima porque si se puedo encontrar como hacer sentar de manera optima a un L1, la solucion optima global contendra la solucion optima para un (G - L1) y la solucion optima local L1.

### Time Complexity:
- Sorting the happiness levels takes O(n log n) time, where n is the number of guests. The rest of the operations, such as creating the minors and majors vectors and computing the maximum enjoyment, can be done in O(n) time. Therefore, the overall time complexity of the solution is O(n log n).
