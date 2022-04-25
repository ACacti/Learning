
#include <iostream>
using namespace std;
inline void sweap(int& a, int& b) {
	int t = a;
	a = b;
	b = t;
}

void heapAdjust(int arr[], int index, int length) {
	int left = index * 2 + 1;
	int right = left + 1;
	int t = index;
	//找出左右子节点和当前节点中最大值的的索引
	if (left < length && arr[t] < arr[left]) {
		t = left;
	}
	if (right < length && arr[t] < arr[right]) {
		t = right;
	}
	if (t != index) {
		//如果当前节点不满足大顶堆的条件，则与最大子节点的值交换
		sweap(arr[t], arr[index]);
		//交换后子节点的值变了，所以要继续调整子节点
		heapAdjust(arr, t, length);
	}
}
//建造一个大顶堆
void makeHeap(int arr[], int length) {
	//从最后一个非叶子节点（最后一个元素的父节点）开始，调节节点，使称为大顶堆
	for (int i = (length - 1) / 2; i >= 0; i--) {
		heapAdjust(arr, i, length);
	}
}


//先将arr构建成一个大顶堆
//不断将堆顶最大数，与数组最后元素交换
//交换后再将剩下的数组元素构建成大顶堆
void heapSort(int arr[], int length) {
	//构建大顶堆
	makeHeap(arr, length);

	//arr中还未排序的长度
	int unsortedLen = length;

	//交换堆顶和当前末尾的节点，重置大顶堆
	for (int i = length - 1; i > 0; i--) {
		sweap(arr[0], arr[i]);
		unsortedLen--;
		heapAdjust(arr, 0, unsortedLen);
	}
}

int main()
{
	int arr[7] = {4,5,7,2,5,2,7};
	heapSort(arr, 6);
	for (int i : arr){
		cout << i << endl;

	}
	return 0;
}