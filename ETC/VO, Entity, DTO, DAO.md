# VO, Entity, DTO, DAO

<aside>
💡 [참고]
[https://velog.io/@ha0kim/DAO-DTO-VO-차이](https://velog.io/@ha0kim/DAO-DTO-VO-%EC%B0%A8%EC%9D%B4)
[https://youngjinmo.github.io/2021/04/dto-vo-entity/](https://youngjinmo.github.io/2021/04/dto-vo-entity/)
[https://gmlwjd9405.github.io/2018/12/25/difference-dao-dto-entity.html](https://gmlwjd9405.github.io/2018/12/25/difference-dao-dto-entity.html)
[추가할 사항]
+POJO

</aside>

# DTO (Data Transfer Object)

- 계층간(Controller, View, Business Layer) 데이터 교환을 위한 객체(**Java Beans**)이다.
    - DB에서 데이터를 얻어 Service나 Controller 등으로 보낼 때 사용하는 객체
    - DB의 데이터가 Presentation Logic Tier로 넘어오게 될 때는 DTO의 모습으로 바뀌어 오고감
    - Controller Layer에서 Response DTO 형태로 Client에 전달
    - Java Beans
        - Java로 작성된 소프트웨어 컴포넌트
        - 비즈니스 로직 부분을 담당하는 Java 프로그램 단위
        - 장점)
            - JSP 페이지가 복잡한 자바 코드로 구성되는 것을 피할 수 있음
            - 재사용 가능한 컴포넌트를 만들 수 있음
- 로직을 갖고 있지 않은 순수한 데이터 객체 (getter/setter 메서드만 갖는다)
- 주로 비동기 처리할 때 사용
- Request와 Response용 DTO는 View를 위한 클래스
    - 자주 변경이 필요한 클래스
    - toEntity() 메서드를 통해 DTO에서 필요한 부분을 이용하여 Entity로 만든다.

![https://user-images.githubusercontent.com/33862991/116250387-a46ec800-a7a8-11eb-8368-8e2df28225fa.png](https://user-images.githubusercontent.com/33862991/116250387-a46ec800-a7a8-11eb-8368-8e2df28225fa.png)

# VO(Value Object)

- 값 그 자체를 표현하는 객체(Read-Only 속성을 갖는 Object)
- 로직을 포함할 수 있으며, 객체의 불변성(객체의 정보가 변경되지 않음)을 보장
- 내부에 선언된 속성의 모든 값들이 같으면 똑같은 객체라고 판별
    - equals()와 hashcode()를 오버라이딩
- 테이블 내에 있는 속성 외 추가적인 속성을 가질 수 있음
- 여러 테이블에 대한 공통 속성을 모아서 만든 BaseVO 클래스를 상속받아서 사용 가능

# VO(Value Object) vs DTO

- DTO는 가변의 성격을 가진 클래스. 데이터 전송을 위해 존재.
- VO는 DTO와 동일한 개념이지만 read only속성을 갖음. (getter만 존재)
- DTO는 인스턴스 개념이라면, VO는 리터럴 개념
- VO는 특정한 비즈니스 값을 담는 객체이고, DTO는 Layer간의 통신 용도로 오고가는 객체를 말함

# Entity

- 실제 DB의 테이블과 1:1로 매핑되는클래스. DB의 테이블 내에 존재한 컬럼만을 속성으로 가져야 함
- 가장 Core한 클래스
- 최대한 외부에서 Entity 클래스의 getter method를 사용하지 않도록 해당 클래스 안에서 필요한 로직 method를 구현한다.
- 단, domain logic만 가지고 있어야 하고, presentation logic을 가지고 있어서는 안된다.
- 여기서 구현한 method는 주로 Service layer에서 사용한다.
- Setter 금지 및 생성자, 접근 제어
    - 객체의 일관성을 유지할 수 있어야 유지 보수성이 올라가기 때문에 setter를 사용해서는 안되며, 객체의 생성자에 값들을 넣어줌으로써 setter 사용을 줄일 수 있다.

# Entity vs DTO

- 두 클래스를 분리하는 이유
    - View Layer와 DB Layer의 역할을 철저하게 분리하기 위해
    - 테이블과 매핑되는 entity클래스가 변경되면 여러 클래스에 영향을 끼치게 되는 반면 View와 통신하는 DTO클래스(Request, Response클래스)는 자주 변경되므로, 분리해야함.
    - Domain Model을아무리 잘 설계했다고 해도, 각 View 내에서 도메인 모델의 getter만을 이용해서 원하는 정보를 표시하기가 어려운 경우가 종종 있음. 이런 경우 도메인 모델 내에 presentation을 위한 필드나 로직을 추가하게 되는데, 이러한 방식이 모델링의 순수성을 깨고 도메인 모델 객체를 망가뜨리게 된다.
    - 또한 도메인 모델을 복잡하게 조합한 형태의 presentation 요구사항들이 있기 때문에 도메인 모델을 직접 사용하는 것은 어렵다.
    - 즉 DTO는 Domain Model을 복사한 형태로, 다양한 presentation logic을 추가한 정도로 사용하며, domain model 객체는 persistent만을 사용한다.

# DAO (Data Access Object)

- 실제로 DB에 접근하는 객체 (Persistence Layer-DB에 데이터를  CRUD하는 계층)
- 직접 DB에 접근하여 데이터를 삽입, 삭제, 조회 등 조작할 수 있는 기능을 수행
- DB와 연결할 Connection까지 설정되어 있는 경우가 많다.
- MyBatis등을 사용할 경우 커넥션 풀까지 제공되고 있기 때문에 DAO를 별도로 만드는 경우는 드물다
- Service와 DB를 연결하는 고리의 역할
- SQL을 사용하여 개발자가 직접 코딩하여 CRUD API를 제공 
- JPA 대부분 기본적인 CRUD method제공
- DataSource : JDBC 명세의 일부분. DB와 관계된 connection정보를 담고 있으며, bean으로 등록하여 인자로 넘겨준다.
- DataSource가 하는 일
    - DB Server와의 기본적인 연결
    - DB Connection Pooling 기능
    : 자바 프로그램에서 데이터베이스 연결(connection 객체를 얻는 작업)은 시간이 많이 걸린다. 만약, 일정량의 Connection을 미리 생성시켜 저장소에 저장했다가 프로그램에서 요청이 있으면 저장소에서 Connection 꺼내 제공한다면 시간을 절약시킬 수 있음. 이러한 프로그래밍 기법을 Connection Pooling이라 한다.
    - 트랜젝션 처리
    - connection pooling을 이용하면 속도와 퍼포먼스가 좋아진다.
