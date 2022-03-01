package com.shj.controller;

import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;

/**
 * @ClassName: TestController
 * @Description:
 * @Author: ShangJin
 * @Create: 2020-02-29 20:52
 **/
@Controller
public class TestController {
    @GetMapping("/test")
    public String test(Model model){
        model.addAttribute("msg", "方法被执行！");
        System.out.println("Controller:被执行");
        return "test";
    }
}