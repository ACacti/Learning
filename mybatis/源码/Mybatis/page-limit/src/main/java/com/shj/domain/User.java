package com.shj.domain;
/**
 * @ClassName: User
 * @Description:
 * @Author: ShangJin
 * @Create: 2020-02-17 19:01
 **/
//实体类
public class User {
    private Integer id;
    private String name;
    private String password;

    public Integer getId() {
        return id;
    }

    public void setId(Integer id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getPassword() {
        return password;
    }

    public void setPassword(String pwd) {
        this.password = pwd;
    }

    public User() {
    }

    @Override
    public String toString() {
        return "User{" +
                "id=" + id +
                ", name='" + name + '\'' +
                ", pwd='" + password + '\'' +
                '}';
    }

    public User(String name, String pwd) {
        this.name = name;
        this.password = pwd;
    }
}