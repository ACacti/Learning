package com.shj.dao;

import com.shj.domain.Teacher;
import com.shj.utils.MybatisUtils;
import org.apache.ibatis.session.SqlSession;
import org.junit.Test;

import java.util.List;

/**
 * @ClassName: DaoTest
 * @Description:
 * @Author: ShangJin
 * @Create: 2020-02-19 14:41
 **/
public class DaoTest {
    @Test
    public void test(){
        SqlSession sqlSession = MybatisUtils.getSqlSession();
        try {
            TeacherMapper teacherDao = sqlSession.getMapper(TeacherMapper.class);
            List<Teacher> teachers = teacherDao.getTeachers();
            for(Teacher teacher:teachers){
                System.out.println(teacher);
            }
        }catch (Exception e){
            e.printStackTrace();
        }finally {
            sqlSession.close();
        }
    }
}