package me.jaeyun.demorestapiwithspring.events;

import com.fasterxml.jackson.databind.ObjectMapper;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.autoconfigure.web.servlet.WebMvcTest;
import org.springframework.hateoas.MediaTypes;
import org.springframework.http.MediaType;
import org.springframework.test.context.junit4.SpringRunner;
import org.springframework.test.web.servlet.MockMvc;

import java.time.LocalDateTime;

import static org.springframework.test.web.servlet.request.MockMvcRequestBuilders.post;
import static org.springframework.test.web.servlet.result.MockMvcResultHandlers.print;
import static org.springframework.test.web.servlet.result.MockMvcResultMatchers.jsonPath;
import static org.springframework.test.web.servlet.result.MockMvcResultMatchers.status;

@RunWith(SpringRunner.class)
@WebMvcTest //Web과 관련된 빈들이 등록됨
public class EventControllerTests {
    // test에서 mock mvc를 주입받아서 쉽게 테스트할 수 있음
    // MockMvc : 요청을만들수있고, 응답을 검증할 수 있는, spring mvc 클래스에서 핵심적인 클래스중하나, 써볼수록 좋음, 웹서버를 만들지 않기 떄문에 좀 더 빠름
    // but dispatcher servlet을 만들어야하기 때문에 단위테스트보다는 빠르지 않음. 만드는 객체도 많고, 구동되는 것이 많기 때문에
    // 웹서버 > mockmvc > 단위테스트
    @Autowired
    MockMvc mockMvc; //mocking되어있는 dispatcher servlet을 상대로 가짜 요청과 그 응답을 확인할 수 있는 테스트를 만들 수 있음(웹과관련된기술만등록을하기때문에 slicing test라고 부름. 즉 계층별로 나눠져, 모든 빈들을 다 등록해서 테스트를 하지않고 웹만하기 떄문에 좀 더 구역을 나눠서 좀 더 빨리 함. 이자체로 단위테스트라고 부르기에는 너무 많인것들이(이벤트컨트롤, 이스베처서블릿, 컨버터 멥퍼 등) 조합되어있어서 이벤트컨트롤러만을 테스트하는 단위컨트롤이라고하기는 좀 어려움

    @Autowired
    ObjectMapper objectMapper;

    @Test
    public void createEvent() throws Exception {
        Event event = Event.builder()
                .name("Spring")
                .description("REST API Development with Spring")
                .beginEnrollmentDateTime(LocalDateTime.of(2018, 11, 23, 14, 21))
                .closeEnrollmentDateTime(LocalDateTime.of(2018, 11, 24, 14, 21))
                .beginEventDateTime(LocalDateTime.of(2018, 11, 25, 14, 21))
                .endEventDateTime(LocalDateTime.of(2018, 11, 26, 14, 21))
                .basePrice(100)
                .maxPrice(200)
                .limitOfEnrollment(100)
                .location("강남역 D2 스타텁 팩토리")
                .build();

        // content를 JSON으로 줘야함
        // json으로 객체 보낼때 : boot를 사용할 때 objectMapper가 임의 빈으로 등록되어있음.
        // mapping jackson json이 의존성으로 들어가있으면 objectMapper를 자동으로 빈으로 등록해줌. -> autowired

        mockMvc.perform(post("/api/events/")
                    .contentType(MediaType.APPLICATION_JSON_UTF8)
                    .accept(MediaTypes.HAL_JSON)
                    .content(objectMapper.writeValueAsString(event)))
                .andDo(print())
                .andExpect(status().isCreated())    // status().isCreated() == 응답 201
                .andExpect(jsonPath("id").exists())
        ;

    }


}
