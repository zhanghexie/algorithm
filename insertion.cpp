/*
 * 插入排序：
 * 每一遍遍历，将起始点之前的序列看成已排序好的，并将起始对应的值点移动到正确位置。
 */

#include<iostream>
#include<vector>
using namespace std;

template<class T>
class Insertion{
	public:
        static void sort(vector<T> &v);

        private:
		static bool greater(vector<T> &v, int a,int b);
		static bool greater(int a,int b);
};

template <class T> void Insertion<T>::sort(vector<T> &v) {
	if(v.size()<=1){
		return;
	}
	for(int i = 1; i < v.size(); i++){
		T temp = v[i];
		int j = i-1;
		// 因为前面是排好序的，所以只要发现前面有不比temp大的就能找到temp应处位置。
		while(j>=0 && greater(v[j],temp)){
			v[j+1] = v[j];
			j--;
		}
		// 这个地方很巧妙，无论是否需要移动，j+1处的值都应该赋值为temp。
		j = j + 1;
		v[j] = temp;
	}
}

template<class T>
bool Insertion<T>::greater(vector<T> &v, int a,int b){
	return v[a] > v[b];
}

template<class T>
bool Insertion<T>::greater(int a,int b){
	return a > b;
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
	Insertion<int>::sort(a);
	show_vector<int>(a);
	return 0;
}
