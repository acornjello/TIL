## Heap Tree
1. 완전이진트리 (Compelete Binary Tree)
	: 트리 원소들을 왼쪽부터 채워나간 형태
2. 여러 개의 값 중에서 가장 크거나 작은 값을 빠르게 찾기 위해 만든 이진 트리
3. 삽입, 삭제 시간 복잡도 : O(logN)
4. 삽입 (최대 힙 가정)
	+ 부모 노드 = idx/2	(1<=idx<=N)
	1. 가장 말단 노드에 노드 삽입
	2. 부모 노드와 비교
	3. 규칙에 맞지 않으면 부모와 교환
	4. 규칙에 맞을 때까지 3과정 반복
	```
	if( arr[idx] < arr[idx/2] ) swap(idx, idx/2);
	else break;
	```
5. 삭제 (최소 힙 가정)
	+ 최댓값 또는 최솟값이 저장된 루트 노드만 제거할 수 있음.
	+ 자식 노드 = (왼) idx*2 (오) idx*2 + 1
	1. 루트 자리에 가장 마지막 노드 삽입.
	2. 올라간 노드와 그의 자식 노드들을 비교
	3. 조건에 만족할 때까지 자식과 교환
	```
	if( idx*2+1 < arr_size ) 
	{
		if( arr[idx*2] < arr[idx*2+1] )
			temp = idx*2+1;
		else
			temp = idx*2;

		if( temp < arr[idx] ) 
			swap(idx, temp);
		else 
			break;
	}
	else 
	{
		if( arr[idx*2] < arr[idx] )
			swap(idx, idx*2);
		else
			break;
	}
	```
6. [Heap Sort](https://github.com/acornjello/TIL/blob/master/Data%20Structure%2C%20Algorithm/Sorting%20Algorithm.md)

## <a name="AVL Tree">AVL Tree
+ 각 노드 마다 왼쪽, 오른쪽 부분 트리의 높이 차가 1보다 크지 않은 성질을 가짐
+ 순회 시간복잡도 : O(logN) / 이반 이진 트리의 worst : O(N)

## Map
+ 인덱스로 int가 아닌 자료형을 사용할 수 있는 배열.
+ map의 내부적인 구조는 각 노드가 key와 value 쌍으로 이뤄진 [균형이진트리(AVL Tree)](#AVL Tree))
+ key는 중복 불가.
+ 검색 속도가 빠름.
	- 이유 : key를 기준으로 정렬된 상태이기 때문이다.
+ unordered_map도 존재.

## Set
+ 많은 자료 중에서 원하는 key를 신속하게 찾고, key가 정렬되기 원할 때 사용.
+ map과 달리 key만 저장하며, key는 중복 불가.
+ key를 중복으로 사용하고 싶다면 multiset을 사용.
+ unordered_set도 존재.