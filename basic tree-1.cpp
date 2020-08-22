#include<iostream>
using namespace std;
class node{
    public:
      node* lchild;
      int data;
      node* rchild;
};
class queue{
    private:
      int size;
      int front;
      int rear;
      node **q;
    public:
      queue(int size);
      ~queue();
      void enqueue(node* data);
      node* dequeue();
      bool isempty();
};
queue::queue(int size){
    this->size = size;
    front =-1;
    rear =-1;
    q= new node* [size];
}
queue::~queue(){
    delete [] q;
}
void queue::enqueue(node* location){
    if(rear==size-1){
        cout<<"queue overflow"<<endl;
    }
    else
    {
        rear++;
        q[rear]=location;
    }
    
}
bool queue::isempty(){
    return rear==front;
}
node* queue::dequeue(){
    if(!isempty()){
        front++;
        return q[front];
    }
    else
    {
        cout<<"queue underflow"<<endl;
        return nullptr;
    }
    
}
class tree{
  private:
    node* root;
  public:
    tree(){root=nullptr;}
    void createTree();
    void Preorder(node* p);
    node* getRoot(){ return root; }
};
void tree::createTree(){
    node *t,*p;
    int data;
    root=new node;
    queue q(25);
    cout<<"enter the value of root";
    cin>>data;
    root->data=data;
    root->lchild=nullptr;
    root->rchild=nullptr;
    q.enqueue(root);
    while(!q.isempty()){
        p=q.dequeue();
        cout<<"enter the leftchild of "<<p->data<<":";
        cin>>data;
        if(data!=-1){
            t=new node;
            t->data=data;
            t->lchild=nullptr;
            t->rchild=nullptr;
            p->lchild=t;
            q.enqueue(t);
        }
        cout<<"enter the rightchild of "<<p->data<<":";
        cin>>data;
        if(data!=-1){
            t=new node;
            t->data=data;
            t->lchild=nullptr;
            t->rchild=nullptr;
            p->rchild=t;
            q.enqueue(t);
        }

    }
}
void tree::Preorder(node *p) {
    if (p){
        cout << p->data << ", " << flush;
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}
int main(){
    tree t;
 
    t.createTree();
 
    cout << "Preorder: " << flush;
    t.Preorder(t.getRoot());
    cout << endl;
    return 0;
}