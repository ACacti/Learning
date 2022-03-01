package com.dynamicsql.domain;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;
import org.apache.ibatis.type.Alias;

import java.util.Date;

/**
 * @ClassName: Blog
 * @Description:
 * @Author: ShangJin
 * @Create: 2020-02-19 16:17
 **/
@Alias("Blog")
@Data
@AllArgsConstructor
@NoArgsConstructor
public class Blog {
    private String id;
    private String title;
    private String author;
    private String createTime;
    private Integer views;
}