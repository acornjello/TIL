package me.jaeyun.demorestapiwithspring;

import org.modelmapper.ModelMapper;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.context.annotation.Bean;

@SpringBootApplication
public class DemoRestApiWithSpringApplication {

    public static void main(String[] args) {
        SpringApplication.run(DemoRestApiWithSpringApplication.class, args);
    }

    // model mapper는 공용으로 쓸수있기 때문에 빈으로 등록
    @Bean
    public ModelMapper modelMapper() {
        return new ModelMapper();
    }
}
