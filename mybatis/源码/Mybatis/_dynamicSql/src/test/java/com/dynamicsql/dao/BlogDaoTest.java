package com.dynamicsql.dao;

import com.dynamicsql.domain.Blog;
import com.dynamicsql.domain.User;
import com.dynamicsql.utils.MybatisUtils;
import org.apache.ibatis.session.SqlSession;
import org.junit.Before;
import org.junit.Test;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * @ClassName: BlogDaoTest
 * @Description:
 * @Author: ShangJin
 * @Create: 2020-02-19 18:45
 **/
public class BlogDaoTest {
    SqlSession sqlSession;
    BlogMapper blogDao;
    @Before
    public void pref(){
        sqlSession = MybatisUtils.getSqlSession();
        blogDao = sqlSession.getMapper(BlogMapper.class);
    }
    @Test
    public void getBlogsTest(){
        Map<String, String> map = new HashMap<>();
        map.put("author", "尚进");
        map.put("title", "Mybatis");
        List<Blog> list1 = blogDao.getBlogs(map);
        for(Blog b : list1){
            System.out.println(b);
        }
    }
    @Test
    public void getBlogsByAuthorTest(){
        User u = new User();
        u.setName("尚进");
        List<Blog> list2 = blogDao.getBlogsByAuthor(u);
        for(Blog b : list2){
            System.out.println(b);
        }
    }
    @Test
    public void getThreeBlogsTest(){
        HashMap<String, List<String>> map = new HashMap<>();
        ArrayList<String> list = new ArrayList<>();
        list.add("尚进");
        list.add("狂风");
        list.add("鲁迅");
        map.put("authors", list);
        List<Blog> blogs = blogDao.getThreeBlogs(map);
        for(Blog b: blogs){
            System.out.println(b);
        }
    }
}