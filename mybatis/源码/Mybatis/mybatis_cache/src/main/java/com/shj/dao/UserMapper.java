package com.shj.dao;

import com.shj.domain.User;
/**
 * @ClassName: UserMapper
 * @Description:
 * @Author: ShangJin
 * @Create: 2020-02-20 14:05
 **/
public interface UserMapper {
    public User getUserById(Integer id);
}