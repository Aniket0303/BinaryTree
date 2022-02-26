#include<iostream>
using namespace std;
#include<stdlib.h>
class Node
{
                  public:
                          Node *left;
                          int data;
                          Node *right;
                  public:
                          Node();
                          ~Node();
                          Node* Create_Node();
                          void Display(Node *p);
};
Node::Node()
{
                  left = NULL;
                  right =NULL;
                  data = -1;
}
Node::~Node()
{
                  delete left;
                  delete right;
}

Node* Node::Create_Node()
{
                  Node *p;
                  p= new Node;
                  cout<<"\n\t Enter the data : ";
                  cin>>p->data;
                  p->left=NULL;
                  p->right=NULL;
                  return p;
}
void Node::Display(Node* q)
{
                 cout<<"\n\t "<<q->data;
}

class BinaryTree : public Node
{
                  private:
                          Node *Root;
                  public:
                          BinaryTree();
                          ~BinaryTree();
                          void Create();
                          void Insert(Node* R,Node *p);
                          void Inorder(Node *p);
                          void Postorder(Node *p);
                          void Preorder(Node *p);
                          Node* ReturnRoot();
};
BinaryTree::BinaryTree()
{
                          Root=NULL;
}
BinaryTree::~BinaryTree()
{
                         delete Root;
}
void BinaryTree::Create()
{
                        Node *p;
                        p=Create_Node();
                       if(Root==NULL)
                     {
                          Root = p;
                    }
                   else
                   {
                    Insert(Root,p);
                   }
}
void BinaryTree::Insert(Node *R, Node *p)
{
                  char ch;
                  cout<<"\n\t Where to insert node at left(l)/right(r) of "<<R->data<<" : ";
                  cin>>ch;
                  if(ch=='l'||ch=='L')
                  {
                     if(R->left==NULL)
                     {
                        R->left=p;
                     }
                     else
                     {
                        Insert(R->left,p);
                     }
                  }
                  else if(ch=='r'||ch=='R')
                  {
                    if(R->right==NULL)
                     {
                        R->right=p;
                     }
                     else
                     {
                        Insert(R->right,p);
                     }
                  }
}
void BinaryTree::Inorder(Node *q)
{
                  if(q!=NULL)
                  {
                    Inorder(q->left);
                    cout<<"  "<<q->data;
                    Inorder(q->right);
                  }
}
void BinaryTree::Preorder(Node *q)
{
                  if(q!=NULL)
                  {
                    cout<<"  "<<q->data;
                    Preorder(q->left);
                    Preorder(q->right);
                  }
}

void BinaryTree::Postorder(Node *q)
{
                  if(q!=NULL)
                  {
                    Postorder(q->left);
                    Postorder(q->right);
                    cout<<"  "<<q->data;
                  }
}
Node* BinaryTree::ReturnRoot()
{
                return Root;
}
int main()
{
                  BinaryTree objBin;
                  Node *p;
                  int ch;
                  char c;
                 do
                 {
                  cout<<"\n\t Menu";
                  cout<<"\n\t 1. Create ";
                  cout<<"\n\t 2. Display ";
                  cout<<"\n\t 3. Search ";
                  cout<<"\n\t 4. Update ";
                  cout<<"\n\t 5. Exit ";
                  cout<<"\n\t Enter your choice(1,2,3,4,5) : ";
                  cin>>ch;
                  switch(ch)
                  {
                    case 1:
                           objBin.Create();
                           break;
                    case 2:
                           cout<<"\n\t Diaplay Menu";
                           cout<<"\n\t 1. Inorder ";
                           cout<<"\n\t 2. Preorder ";
                           cout<<"\n\t 3. Postorder ";
                           cout<<"\n\t 4. All ";
                           cout<<"\n\t Enter your choice(1,2,3) : ";
                           cin>>ch;
                           switch(ch)
                           {
                             case 1:
                                    p=objBin.ReturnRoot();
                                    cout<<"\n\t Inorder : ";
                                    objBin.Inorder(p);
                                    break;
                                case 2:
                                    cout<<"\n\t Preorder : ";
                                    objBin.Preorder(objBin.ReturnRoot());
                                    break;
                                case 3:
                                    cout<<"\n\t Postorder : ";
                                    objBin.Postorder(objBin.ReturnRoot());
                                    break;
                                case 4:
                                    cout<<"\n\t Inorder : ";
                                    objBin.Inorder(objBin.ReturnRoot());
                                    cout<<"\n\t Preorder : ";
                                    objBin.Preorder(objBin.ReturnRoot());
                                    cout<<"\n\t Postorder : ";
                                    objBin.Postorder(objBin.ReturnRoot());
                                    break;
                           }

                           break;
                    case 3:
                           break;
                    case 4:
                           break;
                    case 5:
                           exit(0);
                           break;
                  }
                  cout<<"\n\t Do you want to continue (Y/y) : ";
                  cin>>c;
                 }while(c=='y'||c=='Y');
                  return 0;
}
