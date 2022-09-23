### 하노이

```java
/* 
N : 원판 개수
from : 출발지
temp : 옮기기위해 이동해야하는 장소
to : 목적지
*/

static void hanoi(int N, int from, int temp, int to) {
	if (N==1) {
		System.out.println(from + " " + to);
		return;
	}

	// A->C 옮긴다면, N-1개를 A->B로 이동
	// from의 N-1개 원판을 temp로 옮김
	Hanoi(N-1, from, to, temp);

	// A->C로 이동
	System.out.println(from + " " + to);

	// N-1개를 B에서 C로 이동
	Hanoi(N-1, temp, from, to);

}
```
