package com.shj.dao;

import com.shj.domain.User;
import com.shj.utils.MybatisUtils;
import org.apache.ibatis.session.SqlSession;
import org.junit.Before;
import org.junit.Test;

/**
 * @ClassName: UserDaoTest
 * @Description:
 * @Author: ShangJin
 * @Create: 2020-02-20 14:09
 **/
public class UserDaoTest {

    @Test
    public void daoTest(){
        //同时开启两个会话
        SqlSession sqlSession1 = MybatisUtils.getSqlSession();
        SqlSession sqlSession2 = MybatisUtils.getSqlSession();
        UserMapper userDao1 = sqlSession1.getMapper(UserMapper.class);
        UserMapper userDao2 = sqlSession2.getMapper(UserMapper.class);
        User u1 = userDao1.getUserById(34);
        System.out.println(u1);
        //关闭第一次会话
        sqlSession1.close();
        //第二次会话查询结果
        User u2 = userDao2.getUserById(34);
        System.out.println(u2);
        System.out.println(u1 == u2);
        sqlSession2.close();

    }
}