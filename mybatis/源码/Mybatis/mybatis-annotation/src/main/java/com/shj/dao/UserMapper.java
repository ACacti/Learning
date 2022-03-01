package com.shj.dao;

import com.shj.domain.User;
import org.apache.ibatis.annotations.*;

import java.util.List;

/**
 * @ClassName: UserMapper
 * @Description:
 * @Author: ShangJin
 * @Create: 2020-02-18 17:31
 **/
public interface UserMapper {
    @Select("select * from user")
    public List<User> getUsers();
//    存在多个参数，参数前面必须加@Param()
    @Select("select * from user where id=#{id} and name=#{name};")
    public List<User> getUsersByIdAndName(@Param("id") Integer id, @Param("name") String name);
    @Insert("insert into user(name,pwd) values(#{name},#{pwd});")
    public void addUser(User u);
    @Delete("delete from user where id=#{id};")
    public void delUserById(Integer id);
    @Update("update user set name=#{name}, pwd=#{pwd} where id=#{id};")
    public void updateUser(User u);

}
