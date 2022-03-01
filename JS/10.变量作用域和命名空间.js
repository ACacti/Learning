//1.变量作用空间：未被定义在任何函数里的为全局变量，与window对象绑定
	var x = 12;
	x;//12
	window.x;//12

//2.名字空间：全局变量会绑定到window上，不同的JavaScript文件如果使用了相同的全局变量，或者定义了相同名字的顶层函数，都会造成命名冲突，并且很难被发现。
	//减少冲突的一个方法是把自己的所有变量和函数全部绑定到一个全局变量中

	// 唯一的全局变量MYAPP:
	var MYAPP = {};

	// 其他变量:
	MYAPP.name = 'myapp';
	MYAPP.version = 1.0;

	// 其他函数:
	MYAPP.foo = function () {
 	   return 'foo';
	}

//3.声明常量
	const PI = 3.14

//4.JavaScript的函数定义有个特点，它会先扫描整个函数体的语句，把所有申明的变量“提升”到函数顶部
//声明块级作用域变量let关键字
	function foo0(){
		var sum = 0;
		for(var i = 0; i <= 10; i++){
			sum += i;
		}
		i += 1;//可访问
	}

	function foo1(){
		var sum = 0;
		for(let i = 0; i <= 10; i++){
			sum += i;
		}
		i += 1;//SyntaxError:
	}

//5.解构赋值
	var [x, y, z] = ['hello', 'JavaScript', 'ES6'];//x,y,z分别被赋值数组相应元素

	//嵌套结构赋值
	let [x, [y, z]] = ['hello', ['JavaScript', 'ES6']];

	//忽略某些元素
	let [, , z] = ['hello', 'JavaScript', 'ES6']; // 忽略前两个元素，只对z赋值第三个元素

	//从一个对象中抽取若干属性
	var person = {
    	name: '小明',
    	age: 20,
    	gender: 'male',
    	passport: 'G-12345678',
    	school: 'No.4 middle school'
	};
	var {name, age, passport} = person;//name = 小明, age = 20, passport = G-12345678
	
	//使用的变量名与属性名不一致
	var {name,age, passport:id} = person;//让变量id获得person.passport的值

	//解构赋值使用默认值
	var {name, age, passport, single=true} = person;

	//解决变量已经被声明时再使用解构赋值一般写法会报错
	var x, y;
	({x, y} = { name: '小明', x: 100, y: 200});