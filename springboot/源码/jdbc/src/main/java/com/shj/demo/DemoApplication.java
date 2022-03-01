package com.shj.demo;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.boot.web.servlet.ServletComponentScan;
import org.springframework.context.ApplicationContext;

import javax.sql.DataSource;
import java.sql.SQLOutput;
@ServletComponentScan
@SpringBootApplication
public class DemoApplication {

    public static void main(String[] args) {
       ApplicationContext context = SpringApplication.run(DemoApplication.class, args);
    }

}
