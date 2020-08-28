/*
 * 选择排序：
 * 每一遍遍历选出最小值放到对应开头位置。
 */

#include <cstddef>
#include<iostream>
#include<vector>
using namespace std;

template<class T>
class Selection{
	public:
        static void sort(vector<T> &v);

        private:
		static bool greater(vector<T> &v, int a,int b);
		static void exch(vector<T> &v, int a, int b);
};

template <class T> void Selection<T>::sort(vector<T> &v) {
	for(int i = 0; i < v.size()-1; i++){
		int j = i+1;
		int minIndex = i;
		while(j<v.size()){
			if(v[minIndex]>v[j]){
				minIndex = j;
			}
			j++;
		}
		if (i!=minIndex){
			exch(v, i, minIndex);
		}
	}
}

template<class T>
bool Selection<T>::greater(vector<T> &v, int a,int b){
	return v[a] > v[b];
}

template<class T>
void Selection<T>::exch(vector<T> &v, int a, int b){
	T temp = v[a];
	v[a] = v[b];
	v[b] = temp;
}

template<class T>
void show_vector(vector<T> &a){
	if (a.size()==0){
		return;
	}
	for(int i=0; i<a.size(); i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

int main(){
	vector<int> a = {1,0,-67,2,6,233,15,112,5,6,124};
	show_vector<int>(a);
	Selection<int>::sort(a);
	show_vector<int>(a);
	return 0;
}
