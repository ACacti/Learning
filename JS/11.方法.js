//对象方法
function getAge() {
    var y = new Date().getFullYear();
    return y - this.birth;
}

var xiaoming = {
    name: '小明',
    birth: 1990,
    age: getAge
};

//1.方法内的this指针指代的对象视情况而定：在对象内指代对象，在对象外指代window。
	var foo = xiangming.age;//拿到对象方法
	foo();//NaN错误，因为对象外this指向window(strict 模式中指向undefined)

//2.函数对象的apply()方法可以控制this指向：
	//它接收两个参数，第一个参数就是需要绑定的this变量，第二个参数是Array，表示函数本身的参数
	xiaoming.age(); // 25
	getAge.apply(xiaoming, []); // 25, this指向xiaoming, 参数为空

//3.类似的，函数对象call()方法的使用
	Math.max.apply(null, [3, 5, 4]); // 5
	Math.max.call(null, 3, 5, 4); // 5

//4.装饰器例子：统计parseInt()方法使用次数
	var count = 0;
	var oldParseInt = parseInt; // 保存原函数

	window.parseInt = function () {
    	count += 1;
    	return oldParseInt.apply(null, arguments); // 调用原函数
	};