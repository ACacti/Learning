package com.shj.springbootsecurity.config;

import org.springframework.security.config.annotation.authentication.builders.AuthenticationManagerBuilder;
import org.springframework.security.config.annotation.web.builders.HttpSecurity;
import org.springframework.security.config.annotation.web.configuration.EnableWebSecurity;
import org.springframework.security.config.annotation.web.configuration.WebSecurityConfigurerAdapter;
import org.springframework.security.crypto.bcrypt.BCryptPasswordEncoder;

/**
 * @ClassName: MySecurityConfig
 * @Description:
 * @Author: ShangJin
 * @Create: 2020-02-22 18:32
 **/
@EnableWebSecurity
public class MySecurityConfig  extends WebSecurityConfigurerAdapter {

    //授权
    @Override
    protected void configure(HttpSecurity http) throws Exception {
        //首页所有人可以访问，功能页只有有权限的人才能访问
        //请求授权的规则
        http.authorizeRequests().antMatchers("/").permitAll()//首页所有人都可以访问
                .antMatchers("/level1/**").hasRole("vip1")//level/路径下vip1可以访问
                .antMatchers("/level2/**").hasRole("vip2")//level2/路径下vip2可以访问
                .antMatchers("/level3/**").hasRole("vip3");//level2/路径下vip2可以访问
        //没有权限默认调到登录页面

        //自定义登录页面
        http.formLogin().loginPage("/loginpage")//登录的页面
        .usernameParameter("username")//<input name='username'>
                .passwordParameter("password")//<input type='password' name='password'>
                .loginProcessingUrl("/login");//处理登录的请求（表单提交的url）

        //开启注销功能
        http.logout().logoutSuccessUrl("/");//登出成功后跳转到 '/'
//        //遇到登出或登录失败情况，需要关闭csrf功能
        http.csrf().disable();
        //开启记住我功能
        http.rememberMe()
                //定义记住我 <input type="checkbox" name="remember">
                .rememberMeParameter("remember");
    }


    //认证 springboot 2.1.x 可以直接使用
    //密码编码 PasswordEncoder
    //在Spring Security 5.0+ 新增了很多的加密方法
    @Override
    protected void configure(AuthenticationManagerBuilder auth) throws Exception {
        //这些数据正常应该在数据库中读
        //本示例是从内存中读
        auth.inMemoryAuthentication().passwordEncoder(new BCryptPasswordEncoder())
                .withUser("shangjin").password(new BCryptPasswordEncoder().encode("123456")).roles("vip1", "vip2").and()
                .withUser("root").password(new BCryptPasswordEncoder().encode("1111111")).roles("vip3");
    }
}