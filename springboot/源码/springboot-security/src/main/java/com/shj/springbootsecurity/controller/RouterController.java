package com.shj.springbootsecurity.controller;

import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;

/**
 * @ClassName: RouterController
 * @Description:
 * @Author: ShangJin
 * @Create: 2020-02-22 17:53
 **/
@Controller
public class RouterController {
    @RequestMapping("loginpage")
    public String loginpage(){
        return "view/login";
    }
    @RequestMapping({"/index", "/"})
    public String index(){
        return "index";
    }
    @RequestMapping("/level1/{id}")
    public String level1(@PathVariable("id") int id){
        return "view/level1/page" + id;
    }
    @RequestMapping("/level2/{id}")
    public String level2(@PathVariable("id") int id){
        return "view/level2/page" + id;
    }
    @RequestMapping("/level3/{id}")
    public String level3(@PathVariable("id") int id){
        return "view/level3/page" + id;
    }
}