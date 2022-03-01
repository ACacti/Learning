package com.shj.domain;

/**
 * @ClassName: User
 * @Description:
 * @Author: ShangJin
 * @Create: 2020-02-29 18:41
 **/

public class User {
    private String name;
    private Integer id;
    private String password;

    public User() {
    }

    @Override
    public String toString() {
        return "User{" +
                "name='" + name + '\'' +
                ", id=" + id +
                ", password='" + password + '\'' +
                '}';
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public Integer getId() {
        return id;
    }

    public void setId(Integer id) {
        this.id = id;
    }

    public String getPassword() {
        return password;
    }

    public void setPassword(String password) {
        this.password = password;
    }
}