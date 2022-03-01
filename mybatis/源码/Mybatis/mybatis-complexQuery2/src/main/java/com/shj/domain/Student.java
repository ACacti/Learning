package com.shj.domain;

import lombok.Data;
import org.apache.ibatis.type.Alias;

/**
 * @ClassName: Student
 * @Description:
 * @Author: ShangJin
 * @Create: 2020-02-18 20:09
 **/
@Data
@Alias("Student")
public class Student {
    private Integer id;
    private String name;
    //关联一个老师
    private Integer tid;
}