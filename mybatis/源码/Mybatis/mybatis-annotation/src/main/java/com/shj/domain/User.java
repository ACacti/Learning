package com.shj.domain;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

/**
 * @ClassName: User
 * @Description:
 * @Author: ShangJin
 * @Create: 2020-02-18 17:31
 **/
@Data
@AllArgsConstructor
@NoArgsConstructor
public class User {
    public String name;
    public Integer id;
    public String pwd;
}