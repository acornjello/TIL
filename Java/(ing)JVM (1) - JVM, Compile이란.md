>💡 [참고]
>
>[https://doozi0316.tistory.com/entry/1주차-JVM은-무엇이며-자바-코드는-어떻게-실행하는-것인가](https://doozi0316.tistory.com/entry/1%EC%A3%BC%EC%B0%A8-JVM%EC%9D%80-%EB%AC%B4%EC%97%87%EC%9D%B4%EB%A9%B0-%EC%9E%90%EB%B0%94-%EC%BD%94%EB%93%9C%EB%8A%94-%EC%96%B4%EB%96%BB%EA%B2%8C-%EC%8B%A4%ED%96%89%ED%95%98%EB%8A%94-%EA%B2%83%EC%9D%B8%EA%B0%80)
>
>[https://www.youtube.com/watch?v=VvVruEDCSSY&ab_channel=얄팍한코딩사전](https://www.youtube.com/watch?v=VvVruEDCSSY&ab_channel=%EC%96%84%ED%8C%8D%ED%95%9C%EC%BD%94%EB%94%A9%EC%82%AC%EC%A0%84)
>
>[[우아한Tehck] 무민의 JVM Stack & Heap](https://www.youtube.com/watch?v=UzaGOXKVhwU&ab_channel=우아한Tech)

### (ing)
- C/C++ : 컴파일 언어인데, 컴파일 플랫폼과 타겟 플랫폼이 다를 경우, 프로그램이 동작하지 않음.
    - 플랫폼 = 운영체제 + CPU아키텍처
    - OS마다 지원하는 Systemcall Interface가 다름 등
- 크로스 컴파일 : 따라서, 타겟 플랫폼에 맞춰 컴파일을 해줘야함
- 하지만 Java는 Compiler에 의해 java bytecode로 변환되고 이것은 JVM이 설치된 어느 플랫폼에서든 해석이 가능
- 크로스 컴파일하면 되는데, 굳이 JVM을 사용해야하는가?
    - 자바는 네트워크에 연결된 모든 디바이스에서 작동하는 것이 목적
    - 디바이스마다 운영체제나 하드웨어가 다르기 때문에, 자연스럽게 플랫폼에 의존하지 않도록 언어를 설계 → 그 결과가 Java Bytecode, JVM

**Java 코드가 실행되기까지 - 자바에 있는 Compiler의 Frontend, Backend**

- 두 개의 컴파일러 : Java Compiler(Javac) & JIT Compiler
    - Java Compiler : .class 만들어주는 컴파일러
    - JIT Compiler :
- 컴파일러에서 프론트엔드는 바뀌지 않음.
    - 프론트앤드 : 소스코드를 분석해서 의미를 파악하는 기능 수행

- 자바를 실행하기 위한 가상 기계(컴퓨터)
- Java는 OS에 종속적이지 않다는 특징을 가짐
    - OS에 종속받지 않고 실행되기 위해서는 OS위에서 Java를 실행시킬 무언가가 필요한데 이것이 JVM
    - → OS에 종속받지 않고 CPU가 Java를 인식, 실행할 수 있게하는 가상 컴퓨터
    - 원시코드 .java 는 CPU가 인식하지 못하므로, 컴파일 과정 필요. → .class파일로 변환
    - Java Compiler가 JVM이 인식할 수 있는 .class파일(Java Bytecode)로 변환
    - Java compiler : JDK를 설치하면 bin에 존재하는 javac.exe
        - 즉 JDK에 Java compiler가 포함되어 있음
    - JVM이 OS가 bytecode를 이해할 수 있도록 해석 → 따라서 byte code는 OS 상관없이 실행
- 컴파일언어 (C, Java, ..) 인터프리터언어(Python)

### 컴파일 하는 방법

- Java Compiler의 javac라는 명령어를 사용하면 .java파일을 컴파일하여 .class파일을 만들 수 있다.

### 바이트코드란?

- 자바 바이트 코드 : JVM이 이해할 수 있는 언어로 변환된 자바 소스코드
    - 자바 컴파일러에 의해 변환된 코드의 명령어 크기가 1바이트라서 자바 바이트 코드라고 불림
- 바이트 코드는 다시 실시간 번역기 또는 JIT 컴파일러에 의해 바이너리 코드로 변환된다.
- 바이너리코드 : 컴퓨터가 인식할 수 있는 0과 1로 구성된 이진코드
- 기계어 : 0과 1로 이루어진 바이너리 코드
    - 기계어가 이진코드로 이루어졌을 뿐 모든 이진코드가 기계어인 것은 아님.
    - 특정 언어가 아니라, CPU가 이해하는 명령어 집합. CPU제조사마다 기계어가 다를 수 있음.
- 즉 기계어 → CPU가 이해하는 언어는 바이너리 코드, 가상 머신이 이해하는 코드는 바이트 코드

### JIT Compiler

- Just-In-Time Compliation 또는 Dynamic Translation이라고 함.
- 인터프리터 방식의 단점을 보완하기 위해 도입됨
    - 인터프리터 방식으로 실행하다가 적절한 시점에 바이트 코드 전체를 컴파일하여 기계어로 변경하고,
    - 이후에는 더이상 인터프리팅 하지 않고 기계어로 직접 실행하는 방식
- 기계어(컴파일된 코드)는 캐시에 보관하기 때문에 한 번 컴파일된 코드는 빠르게 수행
    - 물론 JIT컴파일러가 컴파일하는 과정은 바이트 코드를 인터프리팅하는 것보다 훨씬 오래걸림
    - 한 번만 실행되는 코드라면 컴파일 하지 않고, 인터프리팅하는 것이 유리
- 따라서 JIT컴파일러를 사용하는 JVM들은 내부적으로 해당 메서드가 얼마나 자주 수행되는지 체크하고 일정 정도를 넣을때만 컴파일을 수행
- 자바에서는 자바 컴파일러가 .java를 .class(바이트 코드)로 변환한 다음, 
실제 바이트 코드를 실행하는 시점에서 JVM(정확히는 JRE)이 바이트 코드를 JIT컴파일 통해 기계어로 변환
- 바이트 코드를 컴파일하고서, native machine code로 번역해 놓음
    
    → 그리고 동일한 바이트코드 시퀀스에 대해서는 이미 번역된 native machine code를 상요해서 성능을 높여주는 역할을 함.
    

### JRE(Java Runtime Environment)

- runtime vs compile time : 서로 대조됨
    - compile time : 코드 파일을 실행하거나 배포하기 전에 미리해두는 번역작업 시점
    - runtime : 실제 실행하는 시점. compile & build까지 다 된 다음 사용할 곳에 주어져서 실행될때
        - 작성한 Java소스만으로 프로그램이 진행되는게 아님
        (Map, Set 등이 구현된 프로그램이 rt.jar에 있음)
- JRE가 JVM을 포함하고 있음
    
    
### JDK(Java Development Kit)

- JRE가 JVM을 포함하고 있는 것 처럼 JDK도 JRE를 포함
- + 개발에 포함되는 것들 javac, 자바 디버깅할때 쓰는 jdb
- + 서로 연관있는 클래스들을 하나의 JAR파일로 묶어주는 jar 등등
- **javac는 JVM에 있는거 아닌가...?**
