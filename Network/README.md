## **검색시 일어나는 일**
    1. 브라우저에 도메인 입력 -> DNS서버에 IP주소를 요청 -> 수신한 IP주소에 해당하는 웹서버 접속
    2. DHCP : 호스트의 IP주소및 TCP/IP설정을 클라이언트에 자동으로 제공하는 프로토콜
        : 사용자 PC는 DHCP서버에서 사용자 자신의 IP주소, 가장 가까운 라우터의 IP주소, 가장 가까운DNS서버의 IP주소를 받는다. 이후 ARP 프로토콜을 이용하여 IP주소를 기반으로 가장 가까운 라우터의 MAC주소를 알아냄.
    3. 웹서버의 IP주소를 알았으면, http 리퀘스트를 위해 TCP 소켓을 개방하고 연결을 요청한다.
    4. 이때 3-hand-shaking이 일어나고, tcp에 연결에 성공하면 http request가 tcp 소켓을 통해 보내진다.
    5. 이에 대한 응답으로 웹 페이지의 정보가 사용자의 pc로 들어온다.

## REST
- REST는 분산 하이퍼미디어시스템(예:웹)을 위한 아키텍쳐 스타일(제약조건의 집합)
- REST API는 hypertext-driven이어야한다.
- 제약조건
    1. **client-server** // http를 잘따르는 것만해도 1
    2. **stateless**     // 2
    3. **cache**         // 3
    4. **uniform interface** => but잘 만족 못함
        -  리소스가 URI로 식별되야함 (ㅇ)
        -  representation전송을 통해서 리소스를 제작해야한다 : 리소스 업데이트,생성, 삭제 시 http msg에 표현을 하여 전송하고 그것을 잘 수행해야한다. (ㅇ)
        -   self-descriptive msg    : 메시지는 스스로 설명해야한다.
        ex) GET / HHTP/1.1 => host가 없음 (host : www.naver.com 있어야함)
            ex) HTTP/1.1 200 OK
                // Content-Type : application/json => 이게 있어야 본문 해석됨
                [ {"dd" : "www", "path":"/abc}] => 사실 본문도 해석불가
    5. **HATEOAS**(hypermedia as the engine of application state) : 
        : 애플리케이션의 상태가 항상 하이퍼링크를 통해 전달되어야함.  // (x)

        * CS가 각각 독립적으로 진화하기위해 필요
            : 서버의 기능이 변경되어도 클라이언트를 업데이트할 필요가 없다.
            : 웹페이지를 변경했다고 웹브라우절르 업데이터할 필요x 
            : 웹페이지 브라우저 업데이트 -> 페이지 변경 x
            : 어떻게? HTML5 초안 6년 HTTP/1.1 개정 7년
        * 상호운용성에 대한 집착
         

    6. **layered system**      // 4 만족
    7. **code-on-demand** (optional) // 서버에서 코드를 클라이언트로 보내서 실행할 수 있어야함.(js)