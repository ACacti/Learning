package dao;

import com.shj.dao.IUserDaoMapper;
import com.shj.domain.User;
import com.shj.utils.MybatisUtils;
import org.apache.ibatis.session.SqlSession;
import org.junit.Test;

/**
 * @ClassName: UserDaoTest
 * @Description:
 * @Author: ShangJin
 * @Create: 2020-02-17 19:16
 **/
public class UserDaoTest {
    @Test
    public void addUserTest(){
        System.out.println("添加测试");
        SqlSession sqlSession = MybatisUtils.getSqlSession();
        try{
            IUserDaoMapper userDao = sqlSession.getMapper(IUserDaoMapper.class);
            userDao.addUser(new User("李四", "12344"));
            sqlSession.commit();
        }catch (Exception e){
            e.printStackTrace();
        }finally {
            sqlSession.close();
        }
    }
    @Test
    public void delUserTest(){
        System.out.println("删除测试");
        SqlSession sqlSession = MybatisUtils.getSqlSession();
        try{
            IUserDaoMapper userDao = sqlSession.getMapper(IUserDaoMapper.class);
            userDao.delUserById(1);
            sqlSession.commit();
        }catch (Exception e){
            e.printStackTrace();
        }finally {
            sqlSession.close();
        }
    }
//    @Test
//    public void updateUser(){
//        System.out.println("更新测试");
//        SqlSession sqlSession = MybatisUtils.getSqlSession();
//        try{
//            IUserDao userDao = sqlSession.getMapper(IUserDao.class);
//            User user = new User("老王", "233434");
//            user.setId(2);
//            userDao.updateUser(user);
//            sqlSession.commit();
//        }catch (Exception e){
//            e.printStackTrace();
//        }finally {
//            sqlSession.close();
//        }
//    }
//
//    @Test
//    public void findUserTest(){
//        System.out.println("查找测试");
//        SqlSession sqlSession = MybatisUtils.getSqlSession();
//        try{
//            IUserDao userDao = sqlSession.getMapper(IUserDao.class);
//            User user = userDao.getUserById(2);
//            System.out.println(user);
//        }catch (Exception e){
//            e.printStackTrace();
//        }finally {
//            sqlSession.close();
//        }
//    }

}