package com.shj.dao;

import com.shj.domain.Teacher;

import java.util.List;

/**
 * @ClassName: TeacherMapper
 * @Description:
 * @Author: ShangJin
 * @Create: 2020-02-18 20:17
 **/
public interface TeacherMapper {
    public List<Teacher> getTeachers();
}