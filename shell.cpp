/*
 * 希尔排序：
 * 每次循环以比上次更加小的间隔将数组分组，分别对每组进行插入排序，直到间隔变为1。 
 */

#include <cstdlib>
#include<iostream>
#include<vector>
#include<ctime>
#define SIZE_OF_VECTOR 50000
#define SEED 20 
using namespace std;

template<class T>
class Shell{
	public:
        static void sort(vector<T> &v);

        private:
		static bool greater(vector<T> &v, int a,int b);
		static bool greater(int a,int b);
};

template <class T> void Shell<T>::sort(vector<T> &v) {
	if(v.size()<=1){
		return;
	}
	for(int g = v.size()/2; g >= 1; g/=2){
		// 同时对各组进行插入排序。
		for(int i = g; i < v.size(); i++){
			T temp = v[i];
			int j = i-g;
			while(j>=0 && greater(v[j],temp)){
				v[j+g] = v[j];
				j-=g;
			}
			j = j + g;
			v[j] = temp;
		}
	}
}

template<class T>
bool Shell<T>::greater(vector<T> &v, int a,int b){
	return v[a] > v[b];
}

template<class T>
bool Shell<T>::greater(int a,int b){
	return a > b;
}

template<class T>
void show_vector(vector<T> &a,int end = -1){
	if (a.size()==0){
		return;
	}
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
	Shell<int>::sort(a);
	double endT = clock();
	cout << "花费时间:" << (double)(endT-startT) / CLOCKS_PER_SEC << "秒" << endl;
	show_vector<int>(a,100);
	return 0;
}
