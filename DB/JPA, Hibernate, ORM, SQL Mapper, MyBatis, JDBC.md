# ORM, SQL Mapper, JDBC

<aside>
💡 [JDBC, JPA/Hibernate, Mybatis의 차이](https://sugerent.tistory.com/569)(참고정리)
[JDBC, JPA/Hibernate, Mybatis의 차이(원본)](https://gmlwjd9405.github.io/2018/12/25/difference-jdbc-jpa-mybatis.html)
[ORM, SQL Mapper의 차이](https://velog.io/@mu1616/ORM-SQL-Mapper-%EC%B0%A8%EC%9D%B4)
[MyBatis 대비 Spring JDBC의 장점](https://hello-bryan.tistory.com/335)
[Plain JDBC vs Spring JDBC](https://gmlwjd9405.github.io/2018/05/15/setting-for-db-programming.html)
[DAO, DTO, Entity Class 차이](https://gmlwjd9405.github.io/2018/12/25/difference-dao-dto-entity.html)
[MyBatis 보다 Spring JDBC 를 사용해야 하는 이유](https://hello-bryan.tistory.com/335)
JPA와 MyBatis의차이(ORM과 SQL Mapper)
[https://dreaming-soohyun.tistory.com/entry/JPA와-MyBatis의-차이-ORM과-SQL-](https://dreaming-soohyun.tistory.com/entry/JPA%EC%99%80-MyBatis%EC%9D%98-%EC%B0%A8%EC%9D%B4-ORM%EA%B3%BC-SQL-Mapper)

</aside>

비교)

1. orm vs sql mapper
    1. orm) jpa vs hibernate
    2. jpa vs mybatis
    3. hibernate vs mybatis
2. jdbc vs spring jdbc
3. mybatis vs spring jdbc

# Persistence (영속성)

## JPA, Hibernate, ORM, SQL Mapper, MyBatis, JDBC

## 1. Persistence

- 데이터를 생성한 프로그램이 종료 되어도 사라지지 않는 데이터의 특성
- 영속성을 갖지 않는 데이터는 단지 메모리에서만 존재하기 때문에 프로그램을 종료하면 모두 잃어버리게 된다. 때문에 파일 시스템, 관계형 DB, 객체 DB 등을 활용하여 데이터를 영구하게 저장하여 영속성을 부여한다.

### 1-2. Persistence Layer

- 프로그램의 아키텍처에서, 데이터에 영속성을 부여해주는 계층
- JDBC를 이용하여 직접 구현할 수 있지만, Persistence Framework를 이용한 개발이 많이 이뤄진다.

프레젠테이션 계층 - UI 계층
애플리케이션 계층 - 서비스 계층
비즈니스 논리 계층- 도메인 계층
데이터 접근 계층 - 영속 계층

## 2. Persistence Framework

데이터베이스와 연동되는 시스템을 빠르게 개발하고 안정적인 구동을 보장해주는 프레임워크.
프로그램에서 데이터에 ***영속성***을 부여해주는 계층

JDBC를 이용하여 직접 구현할 수 있지만 Persistence Framework를 이용한 개발이 많이 이뤄진다. (JDBC 프로그래밍의 복잡함이나 번거로움 없이 간단한 작업만으로 데이터베이스와 연동되는 시스템을 빠르게 개발할 수 있음)

**<종류>**

1. ORM : 객체를 통해 간접적으로 데이터베이스를 다룸. 객체 관계를 통해 간접적으로 데이터베이스를 생성. (JPA, Hibernate)
2. SQL Mapper : SQL문장으로 직접 데이터베이스 데이터를 다루는 SQL Helper (Mybatis)

## 3. JDBC

모든 Java의 Data Access 기술의 근간. 모든 Persistecne Framework는 내부적으로 JDBC API를 이용한다.

## 4. ORM (Object Relation Mapper)

- 데이터베이스를 객체로 매핑함으로써 객체 간의 관계를 바탕으로 테이블을 관리하는 것
- 장점)
    - SQL문이 아닌 클래스의 메서드를 통해 데이터베이스를 조작 (프로그래밍만 집중할 수 있음)
    - jpa: 추상화된 데이터 접근계층제공 → DB에 종속적이지 않음 → 설정 파일에서 어떤 db 사용하는지 알려주면 얼마든지 db변경 가능
    - mybatis에서는 관련 dao의 파라미터, 결과, sql 등 모두 확인하여 수정해야함. jpa는 이런 일을 대신 해줌
    
- 단점)
    - 직접 SQL을 작성하는 것보다 성능이 떨어짐 (해결법은 있음)
    - 메서드 호출로 db 데이터를 조작하기때문에 세밀함이 떨어짐. (복잡한 통계분석 쿼리를 매서드만으로 해결하기 힘듦) - 완벽한 ORM만으로 서비스 구현하기 어려움.
    - 프로젝트의 복잡성이 커질경우 난이도 또한 올라갈 수 있음(설계를 신중하게 해야함)
    - 러닝커브가 있다.
    - N+1 Problem : 쿼리 1번으로 N건의 데이터를 가져왔는데 원하는 데이터를 얻기 위해 N번 만큼 반복해서 2차적으로 쿼리를 수행하는 문제
        - ex) 2개의 팀, 각각 2명의 멤버. 이때 모든 멤버를 조회→ 맴버들의 팀이 비어있으니까 채워서 반환하기 위해 팀을 각각 쿼리 날려서 가져옴. 멤버가 수천, 수만명이라고 생각하면 비효율적
    - 쿼리 1개를 날렸는데 그것때문에 추가 쿼리가 N개 나간다

### 4-1. JPA (Java Persistence API)

- 관계형 데이터베이스를 어떻게 사용하는지 정의하는 방법일 뿐임
- JPA에 핵심이 되는 인터페이스 EntityManager
- ORM을 사용하기 위한 표준 인터페이스를 모아둔 것
- 사용자가 원하는 JPA구현체를 선택해서 사용가능
    - 대표적인 구현체(ORM Framework) : Hibernate, EclipseLink, DataNucleus 등

### 4-2. Hibernate

- JPA라는 명세의 구현체. 다른 구현체들도있지만, Hibernate 는 굉장히 성숙한 라이브러리
- SQL을 직접 사용하지 않는다고 JDBC API를 사용하지 않는 것은 않음.
    - 개발자가 SQL을 직접 작성하지 않을 뿐임.
- HQL이라는 쿼리 언어를 포함하고 있음.
    - 객체지향적 쿼리 언어
- 장점)
    - 객체지향적으로 데이터 관리 → 비즈니스 로직에 집중
    - 테이블 생성, 변경, 관리가 쉬움
- 단점)
    - 잘 이해하고 있지 않으면 데이터 손실 발생 (Persistence context)
    - 동일한 이유로 성능상 문제 발생할 수 있음.

### 4-3. Spring Data JPA

- 개발자가 JPA를 더 쉽고 편하게 사용할 수 있도록 도와줌,
- JPA를 한단계 추상화시킨 Repository 인터페이스 제공
- Repository 인터페이스에 정해진 규칙대로 메소드를 입력하면 Spring이 알아서 해당 메소드 이름에 적합한 쿼리를 날리는 구현체를 만들어서 Bean에 등록한다.

![81DBF028-7D6C-4424-80AE-6DCA95D25A84.png](ORM,%20SQL%20Mapper,%20JDBC%205e5f2e18404b475dbd852c6514a2ef7a/81DBF028-7D6C-4424-80AE-6DCA95D25A84.png)

# 5. SQL Mapper

개발자가 작성한 SQL 구문으로 RDB에 직접 질의하여 그 결과 값을 객체에 매핑시켜줌.

- 장점)
    - JDBC를 사용했을때 발생하는 불필요한 코드들을 줄일 수 있다.
    - SQL이 코드와 분리되어있어 유지보수가 편하다.
    - SQL 쿼리 그대로 사용하기에 복잡한 JOIN, TUNING 등을 더 수월하게 작성 가능
    - 동적 쿼리 생성에 유용
- 단점)
    - 데이터베이스 설정 변경 시 수정할 부분이 너무 많다.
    - 특정 DB에 종속적이다.

### MyBatis (Java Persistence Framework)

 - 데이터베이스 레코드에 원시타입과 Map 인터페이스, Java POJO를 설정해서 매핑하기 위해 XML과 애노테이션을 사용할 수 있다.

 - SQL Mapper를 지원해주는 Framework (SQL작성을 직접하여 객체와 매핑시켜준다.)
