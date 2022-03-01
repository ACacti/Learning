//字符串
//1.转义字符 \
	'\x41';//等同于 'A'
	//类似可以用\u####表示Unicode字符
	'\u4e2d\u6587';//等同于'中文'
//2.多行字符串 
`
多
行
字符串
`
//3.字符串拼接 + 或者 $
	var name = 'Tom';
	var age = 20;
	var message1 = '你好，' + name + ',今年' + age + '岁。';
	var message2 = `你好， ${name},今年${age}岁。`;//注意是使用的``符号
//4.操作字符串
	var s = 'Hello world!'；
	s.length;// 13
	s[0];//H
	s[13];//undefined 超出范围
	s[0] = 'h';//不会改变字符串
	//常用方法:
		// toUpperCase()字符串变大写
		var upper = s.toUpperCase();// HELLO WORLD!
		// toLowerCase()把一个字符串全部变为小写
		// indexOf()会搜索指定字符串出现的位置
		s.indexOf('world');//7
		s.indexOf('World');//-1
		// substring()返回指定索引区间的子串
		var str = 'hello, world';
		str.substring(0,5);//返回区间[0,5）字符, 'hello'
		str.substring(7);//从索引7开始到结束，返回'world'
