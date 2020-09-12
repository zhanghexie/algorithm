#ifndef MY_LINK_LIST 
#define MY_LINK_LIST 
#define MAX_CAP 65536

template<class T>
class MyLinkNode{
    public:
        T element;
        MyLinkNode* next;
        MyLinkNode();
        MyLinkNode(T element);
};

template <class T> class MyLinkList {
    public:
        MyLinkList();
        void clear();
        bool is_empty();
        int length();
        T get(int i);
        void insert(T t);
        void insert(int i, T t);
        void remove();
        void remove(int i);
        int index_of(T t);
        void show();

    private:
        MyLinkNode<T> *head;
        int N;
};

#endif
