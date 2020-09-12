#ifndef IMPORT
#define IMPORT

template <class T>
class MySequenceList{
    public:
        MySequenceList();
        void clear();
        bool is_empty();
        int length();
        T get(int i);
        void insert(T t);
        void insert(int i, T t);
        void remove(int i);
        int index_of(T t);
        void show();
    private:
        int N;
        int capacity;
        T *elements;

};

#endif
