package com.shj.dao;

import com.shj.domain.Student;

import java.util.List;

/**
 * @ClassName: StudentMapper
 * @Description:
 * @Author: ShangJin
 * @Create: 2020-02-18 20:16
 **/
public interface StudentMapper {
    public List<Student> getStudents();
    public List<Student> getStudents2();
}