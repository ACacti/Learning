//数组
//0.补充：Array也是一个对象，它的每个元素索引也被视为一个属性（可用for in 遍历）
//1.length属性:可直接给该属性赋值导致Array大小变化
	var arr0 = [1, 2, 3.14, 'Hello', null, true];
	arr0.length;//6
	arr0.length = 3;
	arr0;//变为 [1,2,3.14]
	arr0.length = 5;
	arr0;//变为[1,2, 3.14, undefined, undefined]
	//如果通过索引赋值时，索引超过了范围，同样会引起Array大小的变化：
	arr0[10] = 'x';
	arr0.length;//11

//2.indexOf()：搜索一个指定元素的位置，无则返回-1

//3.slice(): 数组切片
	var arr1 = ['A', 'B', 'C', 'D', 'E', 'F', 'G'];
	arr1.slice(0, 3); // 从索引0开始，到索引3结束，但不包括索引3: ['A', 'B', 'C']
	arr1.slice(3); // 从索引3开始到结束: ['D', 'E', 'F', 'G']
	var arrCopy = arr.slice();//常用来复制数组
	arrCopy;//['A', 'B', 'C', 'D', 'E', 'F', 'G']

//4.pop() push():
	var arr2 = [1,2];
	arr.push("A", "B");
	arr;//[1,2,"A","B"]
	arr.pop();//返回'B'
	// 空数组继续pop不会报错，而是返回undefined

//5.unshift shift:如果要往Array的头部添加若干元素，使用unshift()方法，shift()方法则把Array的第一个元素删掉
	var arr3 = [1,2];
	arr3.unshift('A', 'B');
	arr3;//['A', 'B', 1, 2]
	arr3.shift();//'A'
	//空数组继续shift不会报错，而是返回undefined

//6.sort()排序

//7.reverse():数组翻转

//8.splice():该方法是修改Array的“万能方法”，它可以从指定的索引开始删除若干元素，然后再从该位置添加若干元素.
	var arr4 = ['Microsoft', 'Apple', 'Yahoo', 'AOL', 'Excite', 'Oracle'];
	// 从索引2开始删除3个元素,然后再添加两个元素:
	arr4.splice(2, 3, 'Google', 'Facebook'); // 返回删除的元素 ['Yahoo', 'AOL', 'Excite']
	arr4; // ['Microsoft', 'Apple', 'Google', 'Facebook', 'Oracle']
	// 只删除,不添加:
	arr4.splice(2, 2); // ['Google', 'Facebook']
	arr4; // ['Microsoft', 'Apple', 'Oracle']
	// 只添加,不删除:
	arr4.splice(2, 0, 'Google', 'Facebook'); // 返回[],因为没有删除任何元素
	arr4; // ['Microsoft', 'Apple', 'Google', 'Facebook', 'Oracle']

//9.concat():该方法连接另一个数组起来，返回连接后的数组
	var arr5 = [1];
	var added = arr5.concat([2,3,4]);
	added;//[1,2,3,4]
	arr5;//[1]

//10.join():它把当前Array的每个元素都用指定的字符串连接起来，然后返回连接后的字符串
	var arr6 = ['A', 'B', 'C'];
	arr6.join('-');//'A-B-C'
	//如果Array的元素不是字符串，将自动转换为字符串后再连接。

//11.多维数组
	var arr7 = [[1, 2, 3], [400, 500, 600], '-'];
	arr7[1][1];//500