package com.shj.springbootmybatis.controller;

import com.shj.springbootmybatis.dao.UserMapper;
import com.shj.springbootmybatis.domain.User;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.ResponseBody;

import java.util.List;

/**
 * @ClassName: UserController
 * @Description:
 * @Author: ShangJin
 * @Create: 2020-02-21 17:48
 **/
@Controller
public class UserController {
    @Autowired
    private UserMapper userMapper;
    @ResponseBody
    @GetMapping("/find")
    public List<User> findUserList() {
        return userMapper.findUserList();
    }
}