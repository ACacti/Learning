//高阶函数：一个函数接收另一个函数作为参数
//1.map(function (currentValue, index, arr))方法：currentValue当前元素， index当前元素下标， arr迭代的数组
	//map()应用：计算f(x) = x*x
	var f = function (x) {
    	return x * x;
	};

	var arr = [1, 2, 3, 4, 5, 6, 7, 8, 9];
	var result0 = [];
	for (var i=0; i<arr.length; i++) {
	    result0.push(f(arr[i]));
	}
	var result1 = arr.map(f); // [1, 4, 9, 16, 25, 36, 49, 64, 81]
//更多参数详见https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array/map


//2.reduce()方法：[x1, x2, x3, x4].reduce(f) = f(f(f(x1, x2), x3), x4)
	//reduce()方法必须接收连个参数
	//应用：计算数组和
	var arr = [1, 2, 3, 4, 5];
	arr.reduce(function(x, y){
		return x + y;
	})

//3.filter(function(element, index, self))方法：Array的filter()把传入的函数依次作用于每个元素，然后根据返回值是true还是false决定保留还是丢弃该元素。

//练习：
 //1.把一个字符串13579先变成Array——[1, 3, 5, 7, 9]，再利用reduce()就可以写出一个把字符串转换为Number的函数
 	function myIntegerParser(s){
 		var arr = s.split('').map(function(x){return x - '0'});
		return arr.reduce(function(x, y){return x * 10 + y});
 	}

 //2.请把用户输入的不规范的英文名字，变为首字母大写，其他小写的规范名字。输入：['adam', 'LISA', 'barT']，输出：['Adam', 'Lisa', 'Bart']。
 	//解1
 	function foo0(s){
 		return s.map(function(currentValue){
 			var temp = currentValue.toLowerCase().split('');
 			temp[0] = temp[0].toUpperCase();
 			return temp.join('');
 		})
 	}

 	//解2
 	 	function foo1(s){
 		return s.map(function(currentValue){
 			return currentValue[0].toUpperCase() + currentValue.substring(1).toLowerCase();
 		})
 	}

 //3.使用filter()筛选出数组里的素数：
 	function getPrimes(arr){
 		return arr.filter(function(currentValue){
 			if(currentValue <= 1){
 				return false;
 			}
 			else if(currentValue == 2){
 				return true;
 			}
 			else{
 				for(let i = 2; i <= Math.sqrt(currentValue); i++){
 					if(currentValue % i === 0){
 						return false;
 					}
 				}
 				return true;
 			}
 		});
 	}