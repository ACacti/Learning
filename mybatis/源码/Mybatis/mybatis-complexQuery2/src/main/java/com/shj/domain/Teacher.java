package com.shj.domain;

import lombok.Data;
import org.apache.ibatis.type.Alias;

import java.util.List;

/**
 * @ClassName: Teacher
 * @Description:
 * @Author: ShangJin
 * @Create: 2020-02-18 20:11
 **/
@Data
@Alias("Teacher")
public class Teacher {
    public Integer id;
    public String name;
    public List<Student> students;
}