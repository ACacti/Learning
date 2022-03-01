package com.shj.demo.controller;

import com.shj.demo.entry.User;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.jdbc.core.BeanPropertyRowMapper;
import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.ResponseBody;

import javax.sql.DataSource;
import java.util.List;

/**
 * @ClassName: HelloController
 * @Description:
 * @Author: ShangJin
 * @Create: 2020-02-16 19:29
 **/
@Controller
public class HelloController {
    @Autowired
    JdbcTemplate jdbcTemplatel;
    @Autowired
    DataSource dataSource;
    @GetMapping("/query")
    @ResponseBody
    public String map(){

        //List<User> list = jdbcTemplatel.query("select * From user", new BeanPropertyRowMapper<User>(User.class));
        return dataSource.toString();
    }

}