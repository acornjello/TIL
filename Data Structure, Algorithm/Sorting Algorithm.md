# Sorting Algorithm
- 오름차순 정렬으로 가정하여 정리

## Merge Sort
- 시간복잡도 : O(nlogn) / 공간복잡도 : O(n)
- 정렬할 원소들을 반으로 분할해 나가며 각 분할된 리스트 내에서 먼저 정렬 후 병합하며 정렬하는 과정을 통해 정렬하는 알고리즘
- 분할 과정은 크기가 1인 배열로 분할 할때까지 logn만큼 반복
  각 분할된 리스트별로 합병을 진행하므로 시간복잡도 nlogn
- Divde and Conquer을 이용

## Quick Sort
- 시간복잡도 : worst O(n^2), best O(nlogn) / 공간복잡도 : O(n)
- pivot을 선정하여 pivot을 기준으로 좌측과 우측에서 
  pivot보다 작은 값은 왼쪽, pivot보다 큰 값은 오른쪽으로 재배치를 하고 계속해서 분할하여 분할된 배열의 크기가 1이 될때까지 정렬하는 알고리즘
- 최악의 경우 : 이미 정렬되어있는 경우, 분할이 n만큼 일어나므로 시간복잡도가 O(n^2)
  pivot이 최대값이나, 최소값으로 잡히게 될 경우?
  이를 방지하기 위해 원소 값 중 중간값이나 랜덤 값으로 pivot point를 정하는 방법을 사용하기도 함.
- 과정
  1. 배열 원소 중 하나를 pivot point로 선정. (보통 맨 앞 or 맨 뒤 or 중간 값 or 랜덤 값)
  2. 배열의 가장 왼쪽과 가장 오른쪽 idx : left, right
  3. left < right 일 경우에만 pivot과 둘의 원소 값을 비교
    3-1. right 원소 값, pivot 비교
		- right 원소 값 > pivot 이면, --right 후 비교(3-1)를 반복
    	- right 원소 값 < pivot 이면, 비교 중지
    3-2. left 원소 값, pivot 비교
		- left 원소 값 < pivot 이면, ++left 후 비교(3-2)를 반복
		- left 원소 값 > pivot 이면, 비교 중지
  4. left 원소 값과 right 원소 값을 교환하고, 과정 3을 반복
  5. 위 과정이 끝나면 left 원소 값과 pivot 값을 교환
  6. 가장 왼쪽부터 left-1까지, left+1부터 가장 오른쪽까지 나누어 퀵 정렬을 반복

## Heap Sort
- 시간 복잡도 : O(nlogn)
  * 최초로 힙을 만드는 시간복잡도 O(n) + 말단 노드가 루트 노드에 올라오기까지 자리이동 O(nlogn)
- 최대 [힙 트리](https://github.com/acornjello/TIL/blob/master/Data%20Structure%2C%20Algorithm/Data%20Structure.md)(내림차순)나 최소 힙 트리(오름차순)를 구성해 정렬 하는 방법.

## Bubble Sort
- 시간복잡도 : worst O(n^2), best O(n)  / 공간복잡도 : O(n)
- 연속된 두 개의 인덱스를 비교하여, 더 큰 값 오른쪽으로 이동시켜 정렬하는 알고리즘

## Selection Sort
- 시간복잡도 : worst O(n^2), best O(n) / 공간복잡도 : O(n)
- 한 번 순회를 하면서 가장 큰 수를 찾아서 배열의 마지막 위치와 교환하는 알고리즘.
- 이미 정렬되어있는 배열의 경우, 정렬 알고리즘 중 가장 성능을 가짐.
  (앞자리 원소와 한 번만 비교하면 되기 때문)

## Insertion Sort
- 시간복잡도 : worst O(n^2), best O(n)
- 현재 위치보다 아래쪽을 순회하며 현재 위치의 값에 알맞은 위치에 넣어주는 알고리즘.
