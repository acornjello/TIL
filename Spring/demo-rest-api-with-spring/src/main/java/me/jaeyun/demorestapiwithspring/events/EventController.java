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

    //    @Autowired
    //    EventRepository eventRepository;
    // TODO(2) 생성자를 사용할 때 생성자가 하나만 있고, 받아올 파라미터가 빈으로 등록돼있다면 autowired 생략가능 spring 4.3부터

    private final EventRepository eventRepository;

    public EventController(EventRepository eventRepository) {
        this.eventRepository = eventRepository;
    }

    @PostMapping
    public ResponseEntity createEvent(@RequestBody Event event) {
        Event newEvent = this.eventRepository.save(event);  // mock객체이므로 nullpoint exception발생
        URI createUri = linkTo(EventController.class).slash(newEvent.getId()).toUri();

        return ResponseEntity.created(createUri).body(event);
    }
}
