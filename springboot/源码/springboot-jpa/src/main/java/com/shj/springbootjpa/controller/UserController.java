package com.shj.springbootjpa.controller;

import com.shj.springbootjpa.dao.UserRepository;
import com.shj.springbootjpa.domain.User;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RestController;

/**
 * @ClassName: UserController
 * @Description:
 * @Author: ShangJin
 * @Create: 2020-02-21 20:42
 **/
@RestController
public class UserController {
    @Autowired
    UserRepository userRepository;
    @GetMapping("/user/{id}")
    public User getUser(@PathVariable("id") Integer id){
        User u = userRepository.findById(id).orElse(null);
        return u;
    }
    @GetMapping("/user")
    public User insertUser(User user){
        User save = userRepository.save(user);
        return save;
    }
}