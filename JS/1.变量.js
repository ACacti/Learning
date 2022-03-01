//数据类型

  //1.Number
  	NaN; // NaN表示Not a Number，当无法计算结果时用NaN表示
	Infinity; // Infinity表示无限大，当数值超过了JavaScript的Number所能表示的最大值时，就表示为Infinity
	//其余整数、浮点数、科学计数法不做介绍
  //2.字符串
  	var a = 'bc';
  	var b = "bc";
  //3.布尔型
  //4.运算符：JS可对任意数据类型作比较
  	false == 0;//True. ==比较会自动转换数据类型再比较
  	false === 0;//False. ===不会转换数据类型，如果数据类型不一致返回False,如果一致再比较
  	NaN === NaN;//False. NaN与其他所有值都不相等
  	isNaN(NaN);//True. 唯一能判断NaN的函数
  	Math.abs(1 / 3 - (1 - 2 / 3)) < 0.0000001; // true. 比较浮点数
//  null表示一个“空”的值，它和0以及空字符串''不同，0是一个数值，''表示长度为0的字符串，而null表示“空”。

// 在其他语言中，也有类似JavaScript的null的表示，例如Java也用null，Swift用nil，Python用None表示。但是，在JavaScript中，还有一个和null类似的undefined，它表示“未定义”。

// JavaScript的设计者希望用null表示一个空的值，而undefined表示值未定义。事实证明，这并没有什么卵用，区分两者的意义不大。大多数情况下，我们都应该用null。undefined仅仅在判断函数参数是否传递的情况下有用。
  //5.数组:JavaScript的数组可以包括任意数据类型
  var arr = [1,2,3.14,'Hello', null, true];//建议使用
  new Array(1,2,3);
  arr[3];// 'Hello'
  //6.对象
  	var person = {
    name: 'Bob',
    age: 20,
    tags: ['js', 'web', 'mobile'],
    city: 'Beijing',
    hasCar: true,
    zipcode: null
	};
  //7.变量：变量名是大小写英文、数字、$和_的组合，且不能用数字开头
  //8.strict 模式：如果一个变量没有通过var申明就被使用，那么该变量就自动被申明为全局变量：
  //在strict模式下运行的JavaScript代码，强制通过var申明变量，未使用var申明变量就使用的，将导致运行错误。
	i = 10; // i现在是全局变量
	'use strict' // 这是一个字符串，不支持strict模式的浏览器会把它当做一个字符串语句执行，支持strict模式的浏览器将开启strict模式运行JavaScript。
