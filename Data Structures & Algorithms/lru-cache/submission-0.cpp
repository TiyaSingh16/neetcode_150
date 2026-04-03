class Node{
    public:
    int key;
    int val;
    Node* prev;
    Node* next;
    Node(int k,int v): key(k),val(v),prev(nullptr),next(nullptr){};
};
class LRUCache {
    private:
    int cap;
    unordered_map<int,Node*> cache;
    Node* left;
    Node* right;
    void remove(Node* node){
        Node* prev=node->prev;
        Node* nxt=node->next;
        prev->next=nxt;
        nxt->prev=prev;
    }
    void insert(Node* node){
        //right is pointing towards the lru:
        Node* prev=right->prev;
        node->prev=prev;
        prev->next=node;
        node->next=right;
        right->prev=node;
    }
public:
    LRUCache(int capacity) {
       cap=capacity;
       left=new Node(0,0);
       right=new Node(0,0);
       left->next=right;
       right->prev=left;
    }
    
    int get(int key) {
        if(cache.find(key)!=cache.end()){
            Node* node=cache[key];
            remove(node);
            insert(node);
            return node->val;
        }
    return -1;
    }
    
    void put(int key, int val) {
        if(cache.find(key)!=cache.end()){
            remove(cache[key]);
        }
        Node* newnode=new Node(key,val);
        cache[key]=newnode;
        insert(newnode);
        if(cache.size()>cap){
            Node* lru=left->next;
            remove(lru);
            cache.erase(lru->key);
            delete lru;
        }
    }
};
