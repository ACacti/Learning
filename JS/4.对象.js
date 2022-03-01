//对象
//1.示例
	var xiaoming={
		name:'小明',//访问 xiaoming.name或xiaoming['name']
		birth:1997,
		'middle-school':'No.1 Middle School'//访问 xiaoming['middle-school']
	}
	xiaoming.age;//undefined

	//为xiaoming对象增加一个age属性
	xiaoming.age = 18；

	//删除birth属性
	delete xiaoming.birth;

	//删除'middle-school'属性
	delete xiaoming['middle-school'];

	//in判断小明是否拥有某属性。
	'name' in xiaoming;//true
	'middle-school' in xiaoming;// false
	//不过要小心，如果in判断一个属性存在，这个属性不一定是xiaoming的，它可能是xiaoming继承得到的
	//要判断一个属性是否是xiaoming自身拥有的，而不是继承得到的，可以用hasOwnProperty()方法
//2.遍历对象示例
	for(var i in xiaoming){
    	console.log(`${i}:${xiaoming[i]}`);
	}

