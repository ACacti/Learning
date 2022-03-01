package com.shj.springbootjpa.dao;

import com.shj.springbootjpa.domain.User;
import org.springframework.data.jpa.repository.JpaRepository;

/**
 * @ClassName: UserRepository
 * @Description:
 * @Author: ShangJin
 * @Create: 2020-02-21 20:36
 **/
//继承JpaRepository来完成对数据库的操作
public interface UserRepository extends JpaRepository<User, Integer> {
}