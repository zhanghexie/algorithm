#ifndef IMPORT
#define IMPORT

template <class T> class MyStack {
    public:
        MyStack();
        int size();
        bool is_empty();
        void push(T t);
        T pop();
        void show();

    private:
        int N;
        T *elements;
};

#endif
