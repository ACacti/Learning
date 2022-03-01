//循环
//1.for in 循环:一般遍历对象的每一个属性
	var o= {
		name:'xiaoming',
		age: 20,
		city:'ShanDong'
	};
	for(var key in o){
		console.log(key);//'name', 'age', 'city'
	}

	var a = ['A', 'B', 'C'];
	for (var i in a) {
  	  console.log(i); // '0', '1', '2'
    	console.log(a[i]); // 'A', 'B', 'C'
	}

	//因为Array也被视作对象
	a.name = 'Array';
	for(var i in a){
		console.log(i);//'0', '1', '2', 'name'
	}
//2.for of 循环:循环迭代器的每一个元素(貌似无法获取索引)
	var arr = ['A', 'B', 'C'];
	var s = new Set(['A', 'B', 'C']);
	var m = new Map([[1, 'x'], [2, 'y'], [3, 'z']]);
	for (var x of arr) { // 遍历Array
	    console.log(x);
	}
	for (var x of s) { // 遍历Set
 	   console.log(x);
	}
	for (var x of m) { // 遍历Map
 	   console.log(x[0] + '=' + x[1]);
	}