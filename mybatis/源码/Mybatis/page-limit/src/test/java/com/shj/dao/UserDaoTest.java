package com.shj.dao;

import com.shj.domain.User;
import com.shj.utils.MybatisUtils;
import org.apache.ibatis.session.RowBounds;
import org.apache.ibatis.session.SqlSession;
import org.junit.Test;

import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * @ClassName: UserDaoTest
 * @Description:
 * @Author: ShangJin
 * @Create: 2020-02-18 16:02
 **/
public class UserDaoTest {
    @Test
    public void getUserByLimit(){
        SqlSession sqlSession = MybatisUtils.getSqlSession();
        try{
            IUserDaoMapper userDao = sqlSession.getMapper(IUserDaoMapper.class);
            List<User> users = sqlSession.selectList("com.shj.dao.IUserDaoMapper.getUserByRowBounds", null, new RowBounds(1, 2));
            for(User u: users){
                System.out.println(u);
            }
        }catch (Exception e){
            e.printStackTrace();
        }finally {
            sqlSession.close();
        }
    }
}