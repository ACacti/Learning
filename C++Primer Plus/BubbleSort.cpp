/*
* @Author: Shangjin
* @Date:   2022-04-12 21:40:44
* @Last Modified by:   ACacti
* @Last Modified time: 2022-04-12 23:57:55
*/
#include <iostream>
using namespace std;
//升序
void bubbleSort(int arr[], int len)
{
    static int aa = 1;
    for(int i = 0; i < len - 1; i++)
    {
        for(int j = 1; j < len - i; j++)
        {
            if(arr[j] < arr[j - 1])
            {
                int t = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = t;
            }
        }
    }
}