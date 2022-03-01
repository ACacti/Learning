package com.shj.dao;

import com.shj.domain.User;
import com.shj.utils.MybatisUtils;
import org.apache.ibatis.session.SqlSession;
import org.junit.Test;

import java.util.List;

/**
 * @ClassName: UserDaoTest
 * @Description:
 * @Author: ShangJin
 * @Create: 2020-02-18 17:37
 **/
public class UserDaoTest {
    @Test
    public void test(){
        SqlSession sqlSession = MybatisUtils.getSqlSession();
        try {
            UserMapper userDao = sqlSession.getMapper(UserMapper.class);
//            查询
            List<User> users = userDao.getUsers();
            for(User u: users){
                System.out.println(u);
            }
//            增加
            User u = new User();
            u.setName("王五");
            u.setPwd("2334343");
            userDao.addUser(u);
//            删除
            userDao.delUserById(17);
//            修改
            userDao.updateUser(new User("尚进", 20, "wadawd"));
            sqlSession.commit();
        }catch (Exception e){
            e.printStackTrace();
        }finally {
            sqlSession.close();
        }
    }

}