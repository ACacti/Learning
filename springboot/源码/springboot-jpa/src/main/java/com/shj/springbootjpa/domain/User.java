package com.shj.springbootjpa.domain;

import lombok.Data;

import javax.persistence.*;


/**
 * @ClassName: User
 * @Description:
 * @Author: ShangJin
 * @Create: 2020-02-21 20:27
 **/
@Data
//使用JPA注解配置映射关系
@Entity//告诉JPA这是一个实体类
@Table(name = "user")//@Table执行和那个数据表对应；如果省略表明就是user
public class User {
    @Id //这是一个主键
    @GeneratedValue(strategy = GenerationType.IDENTITY)//自增主键
    private Integer id;
    @Column(name = "name", length = 30) //这是和数据表对应的一个列
    private String name;
    @Column//缺省默认列名就是属性名
    private String pwd;
}