#ifndef IMPORT
#define IMPORT
template<class T>
class MyTwoWayLinkNode{
    public:
        T element;
        MyTwoWayLinkNode* next;
        MyTwoWayLinkNode* pre;
        MyTwoWayLinkNode();
        MyTwoWayLinkNode(T element);
};

template <class T> class MyTwoWayLinkList {
    public:
        MyTwoWayLinkList();
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
        MyTwoWayLinkNode<T> *head;
        MyTwoWayLinkNode<T> *tail;
        int N;
};

#endif
