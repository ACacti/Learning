package com.shj.springbootmybatis.config;

import org.apache.ibatis.session.Configuration;
import org.mybatis.spring.boot.autoconfigure.ConfigurationCustomizer;
import org.springframework.context.annotation.Bean;

/**
 * @ClassName: MybatisConfig
 * @Description:
 * @Author: ShangJin
 * @Create: 2020-02-21 18:57
 **/
@org.springframework.context.annotation.Configuration
public class MybatisConfig{
    @Bean
    public ConfigurationCustomizer configurationCustomizer(){
        return new ConfigurationCustomizer() {
            @Override
            public void customize(Configuration configuration) {
                configuration.setMapUnderscoreToCamelCase(true);
            }
        };
    }
}