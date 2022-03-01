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
    private String pwd;

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

    public String getPwd() {
        return pwd;
    }

    public void setPwd(String pwd) {
        this.pwd = pwd;
    }

    public User() {
    }

    @Override
    public String toString() {
        return "User{" +
                "id=" + id +
                ", name='" + name + '\'' +
                ", pwd='" + pwd + '\'' +
                '}';
    }

    public User(String name, String pwd) {
        this.name = name;
        this.pwd = pwd;
    }
}