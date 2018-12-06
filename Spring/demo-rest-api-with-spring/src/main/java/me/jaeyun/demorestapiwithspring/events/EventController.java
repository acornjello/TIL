package me.jaeyun.demorestapiwithspring.events;

import org.springframework.hateoas.MediaTypes;
import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;

import java.net.URI;

import static org.springframework.hateoas.mvc.ControllerLinkBuilder.linkTo;

@Controller
@RequestMapping(value="/api/events", produces = MediaTypes.HAL_JSON_UTF8_VALUE)
public class EventController {

    @PostMapping
    public ResponseEntity createEvent(@RequestBody Event event) {
        /**1. createUri의 헤더를 가지는 201 응답**/
        // created를 보낼때는 항상 uri가있어야함 => hateos가 제공하는 linkto, method on을 사용하면 쉽게 만듦
        // createEvent() 에서 linkto(EventController.class) ==> PostMapping 링크가 EventController에 없을 경우 methodOn 사용
        // createEvent(@RequestBody Event event)로 될 경우 methodOn이 정확한 함수를 찾아가기 위해서 createEvent(null)로 처리
        // URI createUri = linkTo(methodOn(EventController.class).createEvent(event)).slash("{id}").toUri();
        // return ResponseEntity.created(createUri).build();

        event.setId(10);
        URI createUri = linkTo(EventController.class).slash("{id}").toUri();


        return ResponseEntity.created(createUri).body(event);
    }
}
