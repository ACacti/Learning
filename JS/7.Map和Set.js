//Map和Set
//1.Map
	//二维数组初始化Map
	var m1 = new Map([['Michael', 34], ['Bob', 75]]);

	//使用set方法初始化Map
	var m2 = new Map();
	m2.set('Michael', 34);
	m2.set('Bob', 75);
	m2.set(12, 'Xiaoming')
	m2.has('Adam');//false
	m2.delete('Bob');//删除键'Bob'
	m2.get('Bob');//undefined

//2.Set
	var s1 = new Set();//空Set
	var s2 = new Set([1,2,'3']);

	//添加元素
	s1.add(4);

	//删除元素
	s1.delete(4);

