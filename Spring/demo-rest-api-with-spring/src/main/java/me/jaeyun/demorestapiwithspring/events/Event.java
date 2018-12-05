package me.jaeyun.demorestapiwithspring.events;

import lombok.*;

import java.time.LocalDateTime;
//TODO(1) java bean spec으로 만들어져 있는지
// 1. 생성자 만들어져있는지
// 2. getter, setter
// ==> lombok 사용

//TODO(3) builder - lombok plugin 설치
// compile된 클래스에 가보면 builder 메소드 등을 만들어줌(lombok이 함)
// hashcode와 equals 구현시 인스턴스 간에 서로 참조하는 관계게 돼버리면 두 함수에 stack overflow가 일어날 수 있음.
// 더 추가할 수 있음 (of= {"id", "account"}) ==> 다른 엔티티와 연관관계에 해당하는 것을 넣는것은 좋지 않음

@Builder @AllArgsConstructor @NoArgsConstructor
@Getter @Setter @EqualsAndHashCode(of = "id")
// 위 anno를 하나의 custom한 anno로 만들 수 있음 but lombok annot는 meta anno를 지원하지 않음
// @Data : equals and hashcode 구현해줌 but 모든 property 사용

public class Event {

    private Integer id;
    private String name;
    private String description;
    private LocalDateTime beginEnrollmentDateTime;
    private LocalDateTime closeEnrollmentDateTime;
    private LocalDateTime beginEventDateTime;
    private LocalDateTime endEventDateTime;
    private String location; // (optional) 이게 없으면 온라인 모임
    private int basePrice; // (optional)
    private int maxPrice; // (optional)
    private int limitOfEnrollment;
    private boolean offline;
    private boolean free;
    private EventStatus eventStatus;
}
