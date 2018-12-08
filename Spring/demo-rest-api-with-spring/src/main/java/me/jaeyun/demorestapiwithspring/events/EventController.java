package me.jaeyun.demorestapiwithspring.events;

import org.modelmapper.ModelMapper;
import org.springframework.hateoas.MediaTypes;
import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;

import javax.management.modelmbean.ModelMBean;
import java.net.URI;

import static org.springframework.hateoas.mvc.ControllerLinkBuilder.linkTo;

@Controller
@RequestMapping(value="/api/events", produces = MediaTypes.HAL_JSON_UTF8_VALUE)
public class EventController {

    //    @Autowired
    //    EventRepository eventRepository;
    // TODO(2) 생성자를 사용할 때 생성자가 하나만 있고, 받아올 파라미터가 빈으로 등록돼있다면 autowired 생략가능 spring 4.3부터

    private final EventRepository eventRepository;

    private final ModelMapper modelMapper;

    public EventController(EventRepository eventRepository, ModelMapper modelMapper) {
        this.eventRepository = eventRepository;
        this.modelMapper = modelMapper;
    }

    @PostMapping
    public ResponseEntity createEvent(@RequestBody EventDto eventDto) {
        // ModelMapper를 통해 dto를 event로 -- reflection이 있지만 점점 성성 좋아짐
        // 원래는 빌더를 사용해서 다 옮겨야함.
        /**
         *Event event = Event.builder()
         *                 .name(eventDto.getName())
         *                 .description(eventDto.getDescription())
         *                 .build()
         */

        Event event = modelMapper.map(eventDto, Event.class);
        Event newEvent = this.eventRepository.save(event);  // mock객체이므로 nullpoint exception발생
        URI createUri = linkTo(EventController.class).slash(newEvent.getId()).toUri();

        return ResponseEntity.created(createUri).body(event);
    }
}
