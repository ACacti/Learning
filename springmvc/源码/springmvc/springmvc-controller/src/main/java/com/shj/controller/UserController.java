package com.shj.controller;

import com.shj.domain.User;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;

/**
 * @ClassName: UserController
 * @Description:
 * @Author: ShangJin
 * @Create: 2020-02-29 18:46
 **/
@Controller
public class UserController {
    @GetMapping("/user1")
    //前端请求 localhost:8080/user?name=xxx
    public String test1(String name, Model model){
//        1.接收前端参数
//        2.将返回的结果传递给前端
        model.addAttribute("msg", name);
//        3.视图跳转
        return "test";
    }
    @GetMapping("/user2")
    public String test2(@RequestParam("name") String n, Model model){
//        1.接收前端参数
//        2.将返回的结果传递给前端
        model.addAttribute("msg", n);
//        3.视图跳转
        return "test";
    }
    /*
     * 1. 接收前端用户传递的参数，判断参数的名字，假设名字直接在方法上，可以直接使用
     * 2. 假设传递的是一个对象User, 匹配User对象中的字段名，如果名字一致则OK, 否则匹配不到
     */
    @GetMapping("/user3")
    public String test3(User user, Model model){
        model.addAttribute("msg", user);
        return "test";
    }
    @RequestMapping("/user4")
    public String test4(User user, Model model){
        model.addAttribute("msg", user);
        return "test";
    }
}