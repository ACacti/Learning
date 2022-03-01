package com.shj.springbootmybatis.domain;

import lombok.Data;
import org.apache.ibatis.type.Alias;

/**
 * @ClassName: User
 * @Description:
 * @Author: ShangJin
 * @Create: 2020-02-21 17:20
 **/
@Data
@Alias("User")
public class User {
    private Integer id;
    private String name;
    private String pwd;
}