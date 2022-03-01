package com.shj.dao;

import com.shj.domain.Student;
import com.shj.utils.MybatisUtils;
import org.apache.ibatis.session.SqlSession;
import org.junit.Test;

import java.sql.SQLOutput;
import java.util.List;

/**
 * @ClassName: DaoTest
 * @Description:
 * @Author: ShangJin
 * @Create: 2020-02-18 20:23
 **/
public class DaoTest {
    @Test
    public void test(){
        SqlSession sqlSession = MybatisUtils.getSqlSession();
        try{
            StudentMapper studentMapper = sqlSession.getMapper(StudentMapper.class);
            List<Student> students = studentMapper.getStudents2();
            for(Student s: students){
                System.out.println(s);
            }
        }catch (Exception e){
            e.printStackTrace();
        }finally {
            sqlSession.close();
        }
    }
}