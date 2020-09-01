/*
 * 归并排序 
 * 递归的将数列分成两半进行排序，最后排序好的序列合并成一个。
 */

#include <cstdlib>
#include<iostream>
#include<vector>
#include<ctime>
#define SIZE_OF_VECTOR 10000
#define SEED 20 
using namespace std;

template<class T>
class Merge{
	public:
        static void sort(vector<T> &v);
        private:
		static bool greater(vector<T> &v, int a,int b);
		static bool greater(int a,int b);
		static void merge(vector<T> &a, vector<T> &temp, int start, int mid, int end);
		static void sort(vector<T> &v, vector<T> &temp, int start, int end);
};

template <class T> 
void Merge<T>::sort(vector<T> &v) {
	if(v.size()<=1){
		return;
	}
	vector<T> temp;
	for(int i=0; i<v.size(); i++){
		temp.push_back(0);
	}
	Merge<T>::sort(v, temp, 0, v.size()-1);
}

template <class T> 
void Merge<T>::sort(vector<T> &v, vector<T> &temp, int start, int end){
	if(start==end){
		return;
	}
	
	// 递归分解
	int mid = (end+start)/2;
	Merge<T>::sort(v, temp, start, mid);
	Merge<T>::sort(v, temp, mid+1, end);

	// 组合
	Merge<T>::merge(v, temp, start, mid, end);	
}

template<class T>
bool Merge<T>::greater(vector<T> &v, int a,int b){
	return v[a] > v[b];
}

template<class T>
bool Merge<T>::greater(int a,int b){
	return a > b;
}

template<class T>
void Merge<T>::merge(vector<T> &v, vector<T> &temp, int start, int mid, int end){
	int a = start;
	int b = mid+1;
	for(int p = start; p <= end; p++){
		if(a > mid){
			temp[p] = v[b++];  
		}else if (b > end) {
			temp[p] = v[a++];
		}else{
			if(Merge<T>::greater(v,a,b)){
				temp[p] = v[b++];
			}else{
				temp[p] = v[a++];
			}
		}
	}
	for(int i=start; i<=end; i++){
		v[i] = temp[i];
	}
}


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

int main(){
	vector<int> a;
	srand(SEED);
	for(int i = 0; i < SIZE_OF_VECTOR; i++){
		a.push_back(rand()%1000);
	}
	cout << "排序元素个数" << SIZE_OF_VECTOR << "。" << endl;
	show_vector<int>(a,100);
	double startT = clock();
	Merge<int>::sort(a);
	double endT = clock();
	cout << "花费时间:" << (double)(endT-startT) / CLOCKS_PER_SEC << "秒" << endl;
	show_vector<int>(a,100);
	return 0;
}
