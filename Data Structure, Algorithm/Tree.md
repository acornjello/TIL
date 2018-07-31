## Heap Tree
1. ��������Ʈ�� (Compelete Binary Tree)
	: Ʈ�� ���ҵ��� ���ʺ��� ä������ ����
2. ���� ���� �� �߿��� ���� ũ�ų� ���� ���� ������ ã�� ���� ���� ���� Ʈ��
3. ����, ���� �ð� ���⵵ : O(logN)
4. ���� (�ִ� �� ����)
	+ �θ� ��� = idx/2	(1<=idx<=N)
	1. ���� ���� ��忡 ��� ����
	2. �θ� ���� ��
	3. ��Ģ�� ���� ������ �θ�� ��ȯ
	4. ��Ģ�� ���� ������ 3���� �ݺ�
	```
	if( arr[idx] < arr[idx/2] ) swap(idx, idx/2);
	else break;
	```
5. ���� (�ּ� �� ����)
	+ �ִ� �Ǵ� �ּڰ��� ����� ��Ʈ ��常 ������ �� ����.
	+ �ڽ� ��� = (��) idx*2 (��) idx*2 + 1
	1. ��Ʈ �ڸ��� ���� ������ ��� ����.
	2. �ö� ���� ���� �ڽ� ������ ��
	3. ���ǿ� ������ ������ �ڽİ� ��ȯ
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
+ �� ��� ���� ����, ������ �κ� Ʈ���� ���� ���� 1���� ũ�� ���� ������ ����
+ ��ȸ �ð����⵵ : O(logN) / �̹� ���� Ʈ���� worst : O(N)

## Map
+ �ε����� int�� �ƴ� �ڷ����� ����� �� �ִ� �迭.
+ map�� �������� ������ �� ��尡 key�� value ������ �̷��� [��������Ʈ��(AVL Tree)](#AVL Tree))
+ key�� �ߺ� �Ұ�.
+ �˻� �ӵ��� ����.
	- ���� : key�� �������� ���ĵ� �����̱� �����̴�.
+ unordered_map�� ����.

## Set
+ ���� �ڷ� �߿��� ���ϴ� key�� �ż��ϰ� ã��, key�� ���ĵǱ� ���� �� ���.
+ map�� �޸� key�� �����ϸ�, key�� �ߺ� �Ұ�.
+ key�� �ߺ����� ����ϰ� �ʹٸ� multiset�� ���.
+ unordered_set�� ����.