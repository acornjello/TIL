# Persistence (영속성)

## JPA, Hibernate, ORM, SQL Mapper, MyBatis, JDBC

## Persistence

데이터를 생성한 프로그램이 종료 되어도 사라지지 않는 데이터의 특성

영속성을 갖지 않는 데이터는 단지 메모리에서만 존재하기 때문에 프로그램을 종료하면 모두 잃어버리게 된다. 때문에 파일 시스템, 관계형 DB, 객체 DB 등을 활용하여 데이터를 영구하게 저장하여 영속성을 부여한다.

### Persistence Layer

프레젠테이션 계층 - UI 계층

애플리케이션 계층 - 서비스 계층

비즈니스 논리 계층- 도메인 계층

데이터 접근 계층 - 영속 계층

## Persistence Framework

데이터베이스와 연동되는 시스템을 빠르게 개발하고 안정적인 구동을 보장해주는 프래임워크. 프로그램에서 데이터에 영속성을 부여해주는 계층

JDBC를 이용하여 직접 구현할 수 있지만 Persistence Framework를 이용한 개발이 많이 이뤄진다. (JDBC 프로그래밍의 복잡함이나 번거로움 없이 간단한 작업만으로 데이터베이스와 연동되는 시스템을 빠르게 개발할 수 있음)

<종류>

- ORM : 객체를 통해 간접적으로 데이터베이스를 다룸(Hibernate, JPA)
- SQL Mapper : SQL문장으로 직접 데이터베이스 데이터를 다루는 SQL Helper (Mybatis)
- Java Application에서 관계형 데이터베이스를 사용하는 방식을 정의한 인터페이스. 말그대로 인터페이스로, 기능을 수행하는 라이브러리가 아님.

### JPA (Java Persistence API)

- 관계형 데이터베이스를 어떻게 사용하는지 정의하는 방법일 뿐임
- JPA에 핵심이 되는 인터페이스 EntityManager

### Hibernate

- JPA라는 명세의 구현체. 그렇다고 JPA를 사용하기 위해서 반드시 Hibernate를 사용해야하는 것은 아님.
- (DataNucleus, EclipseLink 등 다른 구현체 있음)
- 다만 Hibernate 는 굉장히 성숙한 라이브러리

### Spring Data JPA

- 개발자가 JPA를 더 쉽고 편하게 사용할 수 있도록 도와줌,
- JPA를 한단계 추상화시킨 Repository 인터페이스 제공
- Repository 인터페이스에 정해진 규칙대로 메소드를 입력하면 Spring이 알아서 해당 메소드 이름에 적합한 쿼리를 날리는 구현체를 만들어서 Bean에 등록한다.

## ORM (Object Relation Mapper)

- 대이터베이스를 객체로 매핑함으로써 객체 간의 관계를 바탕으로 테이블을 관리하는 것

### ORM과 Persistence의 차이

### 장점

- SQL문이 아닌 클래스의 메서드를 통해 데이터베이스를 조작 (프로그래밍만 집중할 수 있음)
- jpa: 추상화된 데이터 접근계층제공 → 특정 벤더 종속적이지 않음 → 설정 파일에서 어떤 db 사용하는지 알려주면 얼마든지 db변경 가능
- mybatis에서는 관련 dao의 파라미터, 결과, sql 등 모두 확인하여 수정해야함. jpa는 이런 일을 대신 해줌

### 단점

- 직접 SQL을 작성하는 것보다 성능이 떨어짐 (해결법은 있음)
- 메서드 호출로 db 데이터를 조작하기때문에 세밀함이 떨어짐. (복잡한 통계분석 쿼리를 매서드만으로 해결하기 힘듦)
- 러닝커브가 있다.
- N+1 Problem : 쿼리 1번으로 N건의 데이터를 가져왔는데 원하는 데이터를 얻기 위해 N번 만큼 반복해서 2차적으로 쿼리를 수행하는 문제
    - ex) 2개의 팀, 각각 2명의 멤버. 이때 모든 멤버를 조회→ 맴버들의 팀이 비어있으니까 채워서 반환하기 위해 팀을 각각 쿼리 날려서 가져옴. 멤버가 수천, 수만명이라고 생각하면 비효율적
    - 쿼리 1개를 날렸는데 그것때문에 추가 쿼리가 N개 나간다

## SQL Mapper

작성한 SQL 구문으로 RDB에 직접 질의하여 그 결과 값을 객체에 매핑시켜줌.

### DTO (Data Transfer Object)

- 계층간 데이터 교환을 위한 객체(Java Beans)이다.
    - DB에서 데이터를 얻어 Service나 Controller 등으로 보낼 때 사용하는 객체
    - DB의 데이터가 Presentation Logic Rier로 넘어오게 될 때는 DTO의 모습으로 바뀌어 오고감
    - 로직을 갖고 있지 않은 순수한 데이터 객체 (getter/setter 메서드만 갖는다)
    - Request와 Response용 DTO는 View를 위한 클래스
        - 자주 변경이 필요한 클래스
        - toEntity() 메서드를 통해 DTO에서 필요한 부분을 이용하여 Entity로 만든다.
- VO(Value Object) vs DTO
    - VO는 DTO와 동일한 개념이지만 read only속성을 갖음
    - VO는 특정한 비즈니스 값을 담는 객체이고, DTO는 Layer간의 통신 용도로 오고가는 객체를 말함

### Entity

- 실제 DB의 테이블과 매칭될 클래스
- 가장 Core한클래스
- 최대한 외부에서 Entity 클래스의 getter method를 사용하지 않도록 해당 클래스 안에서 필요한 로직 method를 구현한다.
- 단, domain logic만 가지고 있어야 하고, presentation logic을 가지고 있어서는 안된다.
- 여기서 구현한 method는 주로 service layer에서 사용한다.

### Entity vs DTO

- 두 클래스를 분리하는 이유
- View Layer와 DB Layer의 역할을 철저하게 분리하기 위해
- 테이블과 매핑되는 entity클래스가 변경되면 여러 클래스에 영향을 끼치게 되는 반면 view와 통신하는 DTO클래스(Request, Response클래스)는 자주 변경되므로, 분리해야함.
- Domain Model을아무리 잘 설계했다고 해도, 각 View 내에서 도메인 모델의 getter만을 이용해서 원하는 정보를 표시하기가 어려운 경우가 종종 있음. 이런 경우 도메인 모델 내에 presentation을 위한 필드나 로직을 추가하게 되는데, 이러한 방식이 모델링의 순수성을 깨고 도메인 모델 객체를 망가뜨리게 된다.
- 또한 도메인 모델을 복잡하게 조합한 형태의 presentation 요구사항들이 있기 때문에 도메인 모델을 직접 사용하는 것은 어렵다.
- 즉 DTO는 Domain Model을 복사한 형태로, 다양한 presentation logic을 추가한 정도로 사용하며, domain model 객체는 persistent만을 사용한다.

### DAO (Data Access Object)

- 실제로 DB에 접근하는 객체 (Persistence Layer-DB에 데이터를  CRUD하는 계층)이다.
- Service와 DB를 연결하는 고리의 역할
- SQL을 사용하여 개발자가 직접 코딩하여 CRUD API를 제공 
- JPA 대부분 기본적인 CRUD method제공
- * dao vs dto
- DataSource : JDBC 명세의 일부분. DB와 관계된 connection정보를 담고 있으며, bean으로 등록하여 인자로 넘겨준다.
- DataSource가 하는 일
    - DB Server와의 기본적인 연결
    - DB Connection Pooling 기능
    : 자바 프로그램에서 데이터베이스 연결(connection 객체를 얻는 작업)은 시간이 많이 걸린다. 만약, 일정량의 Connection을 미리 생성시켜 저장소에 저장했다가 프로그램에서 요청이 있으면 저장소에서 Connection 꺼내 제공한다면 시간을 절약시킬 수 있음. 이러한 프로그래밍 기법을 Connection Pooling이라 한다.
    - 트랜젝션 처리
    - connection pooling을 이용하면 속도와 퍼포먼스가 좋아진다.
