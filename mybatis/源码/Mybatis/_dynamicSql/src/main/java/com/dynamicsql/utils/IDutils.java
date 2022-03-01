package com.dynamicsql.utils;

import java.util.UUID;

/**
 * @ClassName: IDutils
 * @Description:
 * @Author: ShangJin
 * @Create: 2020-02-19 16:30
 **/
public class IDutils {
    public static String getId(){
        return UUID.randomUUID().toString().replace("-", "");
    }

}