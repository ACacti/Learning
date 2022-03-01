package com.shj.controller;

import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;

/**
 * @ClassName: HelloController
 * @Description:
 * @Author: ShangJin
 * @Create: 2020-02-24 17:55
 **/
@Controller
public class HelloController {
    @GetMapping("/hello")
    public String hello(Model model){
        //封装数据
        model.addAttribute("msg", "hello, springmvc");
        return "hello";//会被视图解析器处理
    }
}