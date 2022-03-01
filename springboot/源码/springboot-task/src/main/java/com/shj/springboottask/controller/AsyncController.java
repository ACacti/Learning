package com.shj.springboottask.controller;

import com.shj.springboottask.AsynService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RestController;

/**
 * @ClassName: AsyncController
 * @Description:
 * @Author: ShangJin
 * @Create: 2020-02-23 13:54
 **/
@RestController
public class AsyncController {

    @Autowired
    AsynService service;
    @GetMapping("/hello")
    public String hello(){
        service.hello();
        return "OK";
    }
}