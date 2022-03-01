package com.shj.springboottimedtask.service;

import org.springframework.scheduling.annotation.Scheduled;
import org.springframework.stereotype.Service;

/**
 * @ClassName: ScheduledService
 * @Description:
 * @Author: ShangJin
 * @Create: 2020-02-23 15:59
 **/
@Service
public class ScheduledService {
    //cron表达式：
    // 秒  分  时  日  月  周几
    @Scheduled(cron = "0 14 16 * * ?")
    public void hello(){
        System.out.println("Hello 方法被执行.");
    }

}