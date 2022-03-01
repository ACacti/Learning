package com.shj.springboottimedtask;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.scheduling.annotation.EnableScheduling;
import org.springframework.scheduling.annotation.Scheduled;

@SpringBootApplication
@EnableScheduling //开启定时功能的注解

public class SpringbootTimedTaskApplication {

    public static void main(String[] args) {
        SpringApplication.run(SpringbootTimedTaskApplication.class, args);
    }

}
