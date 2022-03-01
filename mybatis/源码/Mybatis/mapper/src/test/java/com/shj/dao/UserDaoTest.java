package com.shj.dao;

import org.apache.log4j.Logger;
import org.junit.Test;

/**
 * @ClassName: UserDaoTest
 * @Description:
 * @Author: ShangJin
 * @Create: 2020-02-18 14:01
 **/
public class UserDaoTest {
    @Test
    public void log4jTest(){
        Logger logger = Logger.getLogger(UserDaoTest.class);
        logger.info("info:进入了testLog4j");
        logger.debug("debug: 进入了testLog4j");
        logger.error("error进入了tetLog4j");
    }
}