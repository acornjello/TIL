## Kruskal Algorithm
1. 간선들을 가중치 순으로 오른차순 정렬 후 정점들을 각 컴포넌트로 초기화 한다.
2. 간선들을 순회하면서 양쪽 정점을 포함한 컴포넌트가 연결되어 있지 않으면(순환이 없다면)
   간선을 선택하고, 연결한다.
3. 간선이 (정점개수-1)개가 뽑혔을 때, 그 간선들과 정점들이 이루는 그래프가 [MST](https://github.com/acornjello/TIL/blob/master/Data%20Structure%2C%20Algorithm/Kruskal%20Algorithm.md/#Spanning)이다.
