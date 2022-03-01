//函数定义
//1.定义一个函数
	function foo0(x){
		//Do something
	}

	//定义一个匿名函数（函数也是一个对象）
	var foo1 = function(x){
		//Do something
	}

//2.调用函数
	foo(1);
	foo(1,2,'abc');//可传入任意参数

//3.arguments获取参数，即使函数不定义任何参数，还是可以拿到参数的值
	function abs(){
		if(arguments.length === 0){
			return 0;
		}
		var x = arguments[0];
		return x >= 0 ? x: -x;
	}
	abs();// 0
	abs(10);//10
	abs(12, -1);//12

//4.rest 获取多余参数
	function foo1(x, y, ...rest){
		console.log(x);
		console.log(y);
		for(var i of rest){
			console.log(i);
		}
	}
	foo1();//undefined undefined undedined
	foo1(1,2);//1 2 undefined
	foo1(1,2,3,4);//1 2 3 4
