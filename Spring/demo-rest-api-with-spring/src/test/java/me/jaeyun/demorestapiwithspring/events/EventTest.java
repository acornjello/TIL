package me.jaeyun.demorestapiwithspring.events;

import org.junit.Test;

import static org.assertj.core.api.Assertions.assertThat;

public class EventTest {
    //TODO(2) builder가 있는지 확인하는 test;
    // builder를 쓰면 손쉽게 이벤트 객체를 만들 수 있음, 좋은점
    // 1. 내가 입력하는 값이 뭔지 알 수 있음, .name, .description

    @Test
    public void builder() {
        Event event = Event.builder().build();

        Event event2 = Event.builder()
                .name("Inflearn Spring REST API")
                .description("REST API development with Spring")
                .build();

        // TODO(4) JAVA BEAN SPEC도 준수해야해서 Default생성자, setter getter도 사용할 수 있어야 함
        // builder 는 public이 아니고, 디폴트생성자가 없음 ==> 추가로 allargsconstructor, noargsconstructor, setter, getter 추가

        assertThat(event).isNotNull();
    }

    @Test
    public void javaBean() {
        //Given
        Event event = new Event();
        String name = "Spring REST API";
        String spring = "REST API development";

        //When
        event.setName("Spring REST API");
        event.setDescription("REST API development");

        //Then
        assertThat(event.getName()).isEqualTo(name);
        assertThat(event.getDescription()).isEqualTo(spring);
    }
}