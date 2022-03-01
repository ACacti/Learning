package com.shj.controller;

import org.apache.ibatis.session.SqlSession;
import org.springframework.web.servlet.ModelAndView;
import org.springframework.web.servlet.mvc.Controller;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 * @ClassName: ControllerDemo
 * @Description:
 * @Author: ShangJin
 * @Create: 2020-02-24 21:55
 **/
//只要实现了Controller接口的类，说明这就是一个控制器
public class ControllerDemo implements Controller {
    @Override
    public ModelAndView handleRequest(HttpServletRequest httpServletRequest, HttpServletResponse httpServletResponse) throws Exception {
        ModelAndView modelAndView = new ModelAndView();
        modelAndView.addObject("msg", "Hello!");
        modelAndView.setViewName("test");
        return modelAndView;
    }
}