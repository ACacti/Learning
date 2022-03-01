package com.shj.springbootmybatis.dao;

import com.shj.springbootmybatis.domain.User;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Options;
import org.springframework.stereotype.Repository;

import java.util.List;

/**
 * @ClassName: UserMapper
 * @Description:
 * @Author: ShangJin
 * @Create: 2020-02-21 17:21
 **/
//这个注解表示这是一个Mybatis 的mapper类
@Mapper
@Repository
public interface UserMapper {
    @Options
    public List<User> findUserList();
    public User findUserById(Integer id);
    public void addUser(User user);
    public int updateUser(User user);
    public int deleteUser(User user);
}