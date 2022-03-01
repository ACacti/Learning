package com.dynamicsql.dao;
import com.dynamicsql.domain.Blog;
import com.dynamicsql.domain.User;
import org.apache.ibatis.annotations.Insert;
import org.apache.ibatis.annotations.Select;

import java.util.List;
import java.util.Map;

/**
 * @ClassName: BlogMapper
 * @Description:
 * @Author: ShangJin
 * @Create: 2020-02-19 16:19
 **/
public interface BlogMapper {
    public List<Blog> getBlogs(Map<String, String> map);
    public List<Blog> getBlogsByAuthor(User user);
    public List<Blog> getThreeBlogs(Map<String,List<String>> map);
}