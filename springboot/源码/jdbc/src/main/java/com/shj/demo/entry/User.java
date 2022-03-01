package com.shj.demo.entry;

/**
 * @ClassName: User
 * @Description:
 * @Author: ShangJin
 * @Create: 2020-02-16 19:34
 **/
public class User {
    private String name;
    private Integer id;
    private Integer gender;

    public User() {
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

    public Integer getGender() {
        return gender;
    }

    public void setGender(Integer gender) {
        this.gender = gender;
    }
}