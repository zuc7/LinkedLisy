using namespace std;

class LinkedList{
    public:
    LinkedList();

    void insert_front(int d); // time O(1)
    void insert_back(int d); // time O(N)
    void insert_mid(int d, int pos); // time O(pos)

    void remove_front();
    void remove_back();
    void remove_mid(int pos);
    void removeMult(int val);
    int get_data(int pos);

    bool is_empty();

    void print();
    int media();
    int nearMedia();
    private: 
    class s_node{
        private:
        int data;
        s_node *next;

        public:
        s_node();
        s_node(int data);
        s_node(int data, s_node *next);

        int get_data();
        void set_data(int d);
        s_node *get_next();
        void set_next(s_node *n);
    };
    
    s_node *start;
};