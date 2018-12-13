package me.jaeyun.demorestapiwithspring.events;

import org.modelmapper.ModelMapper;
import org.springframework.hateoas.MediaTypes;
import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Controller;
import org.springframework.validation.Errors;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;

import javax.validation.Valid;
import java.net.URI;

import static org.springframework.hateoas.mvc.ControllerLinkBuilder.linkTo;

@Controller
@RequestMapping(value="/api/events", produces = MediaTypes.HAL_JSON_UTF8_VALUE)
public class EventController {

    private final EventRepository eventRepository;

    private final ModelMapper modelMapper;

    private final EventValidator eventValidator;

    public EventController(EventRepository eventRepository, ModelMapper modelMapper, EventValidator eventValidator) {
        this.eventRepository = eventRepository;
        this.modelMapper = modelMapper;
        this.eventValidator = eventValidator;
    }

    // valid : request에 들어오는 값들을 바인딩할때 anno에 대한 검증을 수행할 수 있음.
    // 이 검증을 수행한 결과를 그 객체 오른쪽에 있는 error에 담아줌.

    @PostMapping
    public ResponseEntity createEvent(@RequestBody @Valid EventDto eventDto, Errors errors) {
        if(errors.hasErrors()) {
            return ResponseEntity.badRequest().body(errors);
        }
        eventValidator.validate(eventDto, errors);
        if(errors.hasErrors()) {
            return ResponseEntity.badRequest().body(errors);
            // serialization - object->json 반대 deserialization
            // body(errors) 는 json으로 변환할 수 없음 => event라는 도메인은 java properties
            // body에 담아준 event객체를 json으로 변환할 때 objectMapper를 사용함.
            // objectMapper는 BeanSerializer를 이용하여 Java의 bean스펙을 준수한 객체인 Event를 변환할 수 있었음.
            // (아무런 custom한 serializer 없이도)
            // but errors는 java bean 스펙을 준수한 객체가 아님. -> bean serializer를 이용하여 json으로 변환할 수 없음.
            // produce 설정때문에 body에 errors를 담으면 json으로 변환하려는 시도가 있음-> 에러남
        }

        Event event = modelMapper.map(eventDto, Event.class);
        Event newEvent = this.eventRepository.save(event);
        URI createUri = linkTo(EventController.class).slash(newEvent.getId()).toUri();

        return ResponseEntity.created(createUri).body(event);
    }
}
