package com.shj.springboottask;

import org.springframework.scheduling.annotation.Async;
import org.springframework.stereotype.Service;

/**
 * @ClassName: AsynService
 * @Description:
 * @Author: ShangJin
 * @Create: 2020-02-23 13:52
 **/
@Service
public class AsynService {
    //注解这是一个异步任务
    @Async
    public void hello(){
        try{
            Thread.sleep(2000);
        }catch (Exception e){
            e.printStackTrace();
        }
        System.out.println("数据正在处理.....");
    }
}