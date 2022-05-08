## Sequence vs MAX+1

- Sequence 
- 가장 효율적이고 정확한 방법
- 크리티컬 세션이 보장되기때문에 절대 데이터의 중복처리가 되지 않음
    - 생성 예제
        
        ```sql
        CREATE SEQUENCE EXAMPLE.SEQ
          WITH 1 INCREMENT BY 1 MAXVALUE 100000000 NOCYCLE CACHE 20;
        ```
        
        - EXAMPLE.SEQ : 시퀀스명
        - START WITH 1 : 시작번호
        - INCREMENT BY 1 : 증가되는 단위, 양/음수 가능
        - MAXVALUE : 시퀀스 최대값
        - NOCYCLE : 최대값 도달 시 에러발생 후 중지하는 옵션 (디폴트)
        - CYCLE : 최대값도달시 MINVALUE(1)부터 다시 시작
        - CACHE : 미리 메모리상(SGA)에 20개의 일련번호를 생성해두는 옵션.(일련번호가 동시에 많이 필요한 경우 유용. 디폴트 20)

```sql
> SELECT EXAMPLE.SEQ.NEXTVAL FROM DUAL; // 호출할 때마다 증가된 값 리턴
> SELECT EXAMPLE.SEQ.CURRVAL FROM DUAL; // 호출할 때마다 현재 값 리턴
// 문자형 일련번호 생성
> SELECT TO_CHAR(EXAMPLE.SEQ.NEXTVAL, 'fm0000000000') FROM DUAL
```

- MAX()+1
- 데이터 중복 가능성을 염두하여 개발진행해야함.
- Sequence보다 성능상 비효율적
- INDEX FAST FULL SCAN을 사용 → Leaf Node 전체를 Multi Block I/O를 통해 읽게 됨 → 모든 Index Entry를 읽게됨
- 일련번호 1개를 채번하기 위해서 지나친 비효율성

```sql
CREATE TABLE MYTABLE {
	SERIAL_ID INTEGER NOT NULL,
	NAME      VARCHAR2(60)
}

// 아무것도 나오지 않음
> SELECT MAX(SERIAL_ID) + 1 FROM MYTABLE;
// NVL처리 : 아무것도 없는 경우 일련번호 0부터 처리하도록 -> 그래도 아무것도 나오지 않음
> SELECT MAX(NVL(SERIAL_ID, 0)) + 1 FROM MYTABLE;
// MAX()함수는 주어진 값들 중에서 제을 큰 값을 반환 -> 주어진 값이 없기 때문에 결과가 없음
> SELECT DECODE(COUNT(*), 0, 1, MAX(SERIAL_ID) + 1) FROM MYTABLE;
// 이렇게 하면 깔끔
> SELECT NVL(MAX(SERIAL_ID), 0) + 1 FROM MYTABLE;
```

- [Sequence를 사용하지 않고, 중복 없게 채번하는 방법](https://scarlett.tistory.com/entry/%EC%B1%84%EB%B2%88%ED%85%8C%EC%9D%B4%EB%B8%94%EC%9D%84-%EC%9D%B4%EC%9A%A9%ED%95%9C-%EC%9D%BC%EB%A0%A8%EB%B2%88%ED%98%B8-%EB%A7%8C%EB%93%A4%EA%B8%B0)
- 채번테이블을 만들어야함..? (채번테이블은 1개의 row만 존재)
- [Oracle Lock 채번](https://ysyblog.tistory.com/233)
