## 建表

```sql
//主键 外键 自增 级联 UNIQUE
CREATE TABLE user  (
  `id` int(0) NOT NULL DEFAULT 1222222 AUTO_INCREMENT,
  `uid` int(255) NULL,
   `name` varchar(20) NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `uname`(`name`)
  CONSTRAINT `fkuid` FOREIGN KEY (`uid`) REFERENCES `user` (`id`) ON DELETE CASCADE ON UPDATE CASCADE
)ENGINE=InnoDB DEFAULT CHARSET=utf8;
```

