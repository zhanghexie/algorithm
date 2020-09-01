/*
 * 快速排序 
 * 将数列按某个值为界，小于放左边，大于放右边，然后递归的对左右两个数列进行同样操作。
 */

#include <cstdlib>
#include<iostream>
#include<vector>
#include<ctime>
#define SIZE_OF_VECTOR 10000
#define SEED 20 
using namespace std;

template<class T>
void show_vector(vector<T> &a,int end = -1){

	if(end == -1 || end > a.size()){
		end = a.size();
	}
	for(int i=0; i < end; i++){
		cout << a[i] << " ";
	}
	cout << endl;
}

template<class T>
class Quick{
	public:
        static void sort(vector<T> &v);
        private:
		static bool greater(vector<T> &v, int a,int b);
		static bool greater(int a,int b);
		static void sort(vector<T> &v, int start, int end);
		static void exch(vector<T> &v, int a, int b);
		static int partition(vector<T> &v, int start, int end);

};

template <class T> 
void Quick<T>::sort(vector<T> &v) {
	Quick<T>::sort(v, 0, v.size()-1);
}

template <class T> 
void Quick<T>::sort(vector<T> &v, int start, int end){
	if(start==end){
		return;
	}else if(end - start == 1){
		if (Quick<T>::greater(v, start, end)){
			Quick<T>::exch(v, start, end);
		}
		return;
	}
	int mid = Quick<T>::partition(v, start, end);
	if (start < mid){
		Quick<T>::sort(v, start, mid-1);
	}
	if (end > mid){
		Quick<T>::sort(v, mid + 1, end);
	}
}

template<class T>
int Quick<T>::partition(vector<T> &v, int start, int end){
	T mid_value = v[start];
	int ps = start;
	int pe = end+1;
	while(true){
		while(true){
			if (pe-1 < start || v[--pe] < mid_value) break;
		}
		while(v[++ps]<mid_value){
			if (ps+1 > end || v[++ps] > mid_value) break;
		}
		if(ps > pe){
			break;
		}else{
			Quick<T>::exch(v, ps,pe);
		}

	}
	Quick<T>::exch(v,start,pe);
	return pe;
}

template<class T>
bool Quick<T>::greater(vector<T> &v, int a,int b){
	return v[a] > v[b];
}

template<class T>
bool Quick<T>::greater(int a,int b){
	return a > b;
}

template<class T>
void Quick<T>::exch(vector<T> &v, int a, int b){
	int temp = v[b];
	v[b] = v[a];
	v[a] = temp;
}


int main(){
	vector<int> a;
	srand(SEED);
	for(int i = 0; i < SIZE_OF_VECTOR; i++){
		a.push_back(rand()%1000);
	}
	cout << "排序元素个数" << SIZE_OF_VECTOR << "。" << endl;
	show_vector<int>(a,100);
	double startT = clock();
	Quick<int>::sort(a);
	double endT = clock();
	cout << "花费时间:" << (double)(endT-startT) / CLOCKS_PER_SEC << "秒" << endl;
	show_vector<int>(a,100);
	return 0;
}
