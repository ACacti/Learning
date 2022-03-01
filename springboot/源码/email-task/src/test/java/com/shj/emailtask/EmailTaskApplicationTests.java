package com.shj.emailtask;

import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.boot.web.servlet.FilterRegistrationBean;
import org.springframework.mail.SimpleMailMessage;
import org.springframework.mail.javamail.JavaMailSenderImpl;
import org.springframework.mail.javamail.MimeMessageHelper;

import javax.mail.MessagingException;
import javax.mail.internet.MimeMessage;
import java.io.File;
import java.io.InputStream;
import java.net.URL;

@SpringBootTest
class EmailTaskApplicationTests {
    @Autowired
    JavaMailSenderImpl mailSender;

//    一个简单的邮件
    @Test
    /*
     * @Title: contextLoads
     * @Description:
     * @param htlm:
     * @return void
     * @Author: ShangJin
     * @Date: 2020/2/23
     */
    void contextLoads(boolean htlm) {
        SimpleMailMessage simpleMailMessage = new SimpleMailMessage();
        simpleMailMessage.setTo("1694634080@qq.com");
        simpleMailMessage.setText("这是一封简单邮件");
        simpleMailMessage.setFrom("shangjinv6@163.com");
        simpleMailMessage.setSubject("简单邮件测试");
        mailSender.send(simpleMailMessage);
    }
    @Test
    //复杂的邮件
    void complexMail() throws MessagingException {
        MimeMessage message = mailSender.createMimeMessage();
        //组装
        MimeMessageHelper mimeMessageHelper = new MimeMessageHelper(message, true);//true: 开启多文件
        mimeMessageHelper.setSubject("复杂邮件测试");
        mimeMessageHelper.setText("<h1>这是一封复杂邮件</h1>", true);//true: 支持html内容
        mimeMessageHelper.setTo("1694634080@qq.com");
        mimeMessageHelper.setFrom("shangjinv6@163.com");
        // 附件

        mimeMessageHelper.addAttachment("1.jpg", new File("C:\\Users\\ShangJin\\Desktop\\email-task\\src\\main\\resources\\2.jpg"));
        mimeMessageHelper.addAttachment("2.ipg", new File("C:\\Users\\ShangJin\\Desktop\\email-task\\src\\main\\resources\\1.jpg"));

        mailSender.send(message);

    }

}
