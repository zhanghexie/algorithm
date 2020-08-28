#include <cstddef>
#include<iostream>
#include<vector>
using namespace std;

template<class T>
class Bubble{
	public:
        static void sort(vector<T> &v);

        private:
		static bool greater(vector<T> &v, int a,int b);
		static void exch(vector<T> &v, int a, int b);
};

template <class T> void Bubble<T>::sort(vector<T> &v) {
	for (int epoch = 0; epoch < v.size() - 1; epoch++) {
		int i = 0;
		while (i < v.size()-epoch-1) {
			if(greater(v, i, i+1)){
				Bubble<T>::exch(v,i,i+1);
			}	
			i++;
		}
  	}
}

template<class T>
bool Bubble<T>::greater(vector<T> &v, int a,int b){
	return v[a] > v[b];
}

template<class T>
void Bubble<T>::exch(vector<T> &v, int a, int b){
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
	vector<int> a = {1,3,67,2,6,2,15,1,5,6,124};
	show_vector<int>(a);
	Bubble<int>::sort(a);
	show_vector<int>(a);
	return 0;
}
