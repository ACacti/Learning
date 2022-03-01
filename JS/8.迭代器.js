//iterator
//1.使用forEach()迭代数组
	var a = ['A', 'B', 'C'];
	a.forEach(function (element, index, array) {
  	  // element: 指向当前元素的值
  	  // index: 指向当前索引
  	  // array: 指向Array对象本身
	    console.log(element + ', index = ' + index);
	});

//2.使用forEach()迭代Set
	var s = new Set(['A', 'B', 'C']);
	s.forEach(function (element, sameElement, set) {
   		console.log(element);
	});

//3.使用forEach()迭代Map
	var m = new Map([[1, 'x'], [2, 'y'], [3, 'z']]);
	m.forEach(function (value, key, map) {
    	console.log(value);
	});