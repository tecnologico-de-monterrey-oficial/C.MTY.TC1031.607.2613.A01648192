#ifndef BST_H
#define BST_H

#include "NodeT.h"
#include <iostream>
#include <stdexcept>
#include <queue>

using namespace std;

template <typename T>
class BST{
private:
    NodeT<T>* root;
    void printTree(NodeT<T>* node, string prefix, bool isRight, bool isRoot);
    void clear(NodeT<T>* node);
    void preOrder(NodeT<T>* node);
    void inOrder(NodeT<T>* node);
    void postOrder(NodeT<T>* node);
    void levelByLevel(NodeT<T>* node);
    int heightRec(NodeT<T>* node);

public:
    BST(): root(nullptr) {}
    ~BST();
    void insert(T data);
    bool find(T data);
    void print();
    void visit(int method);
    void remove(T data);
    int height();
    void ancestors(T data);
    int whatLevelAmI(T data);
};

template <typename T>
BST<T>::~BST(){
    clear(root);
}

template <typename T>
void BST<T>::clear(NodeT<T>* node){
    if(node != nullptr){
        clear(node->left);
        clear(node->right);
        delete node;
    }
}

template <typename T>
void BST<T>::insert(T data){
    if(root == nullptr){
        root= new NodeT<T>(data);
    }else{
        NodeT<T>* aux= root;
        NodeT<T>* father= root;
        while(aux != nullptr){
            if(aux->data == data){
                return;
            }else{
                father= aux;
                if(data < aux->data){
                    aux= aux->left;
                }else{
                    aux= aux->right;
                }
            }
        }
        if(data < father->data){
            father->left= new NodeT<T>(data);
        }else{
            father->right= new NodeT<T>(data);
        }
    }
}

template <typename T>
bool BST<T>::find(T data){
    if(root == nullptr){
        return false;
    }else{
        NodeT<T>* aux= root;
        while(aux != nullptr){
            if(aux->data == data){
                return true;
            }else{
                if(data < aux->data){
                    aux= aux->left;
                }else{
                    aux= aux->right;
                }
            }
        }
        return false;
    }
}

template <typename T>
void BST<T>::remove(T data){
    if(root != nullptr){
        if(root->data == data){
            if(root->left == nullptr && root->right == nullptr){
                NodeT<T>* aux= root;
                root= nullptr;
                delete aux;
                return;
            }
            if(root->left == nullptr || root->right == nullptr){
                NodeT<T>* aux= root;
                root= (root->left == nullptr) ? root->right : root->left;
                delete aux;
                return;
            }
            NodeT<T>* aux= root;
            if(aux->left->right == nullptr){
                NodeT<T>* auxRemove= aux->left;
                aux->data= auxRemove->data;
                aux->left= auxRemove->left;
                delete auxRemove;
                return;
            }else{
                NodeT<T>* fatherRemove= aux->left;
                NodeT<T>* auxRemove= fatherRemove->right;
                while(auxRemove->right != nullptr){
                    fatherRemove= auxRemove;
                    auxRemove= auxRemove->right;
                }
                aux->data= auxRemove->data;
                fatherRemove->right= auxRemove->left; 
                delete auxRemove;
                return;
            }
        }else{
            NodeT<T>* father= root;
            NodeT<T>* aux= (data < root->data) ? root->left : root->right;
            while(aux != nullptr){
                if(aux->data == data){
                    if(aux->left == nullptr && aux->right == nullptr){
                        (data < father->data) ? father->left= nullptr : father->right= nullptr;
                        delete aux;
                        return;
                    }
                    if(aux->left == nullptr || aux->right == nullptr){ 
                        if(data < father->data){
                            father->left= (aux->left != nullptr) ? aux->left : aux->right;
                        }else{
                            father->right= (aux->left != nullptr) ? aux->left : aux->right;
                        }
                        delete aux;
                        return;
                    }
                    if(aux->left->right == nullptr){
                        NodeT<T>* auxRemove= aux->left;
                        aux->data= auxRemove->data;
                        aux->left= auxRemove->left;
                        delete auxRemove;
                        return;
                    }else{
                        NodeT<T>* fatherRemove= aux->left;
                        NodeT<T>* auxRemove= fatherRemove->right;
                        while(auxRemove->right != nullptr){
                            fatherRemove= auxRemove;
                            auxRemove= auxRemove->right;
                        }
                        aux->data= auxRemove->data;
                        fatherRemove->right= auxRemove->left; 
                        delete auxRemove;
                        return;
                    }
                }else{
                    father= aux;
                    aux= (data < aux->data) ? aux->left : aux->right;  
                }
            }
            throw out_of_range("El nodo a borrar no existe");
        }
    }
}

template <typename T>
void BST<T>::printTree(NodeT<T>* node, string prefix, bool isRight, bool isRoot){
    if(node == nullptr) return;
    printTree(node->right, prefix + (isRoot ? "" : (isRight ? "      " : "|     ")), true, false);
    cout<<prefix<<(isRoot ? "" : (isRight ? ".---- " : "`---- "))<<node->data<<endl;
    printTree(node->left,  prefix + (isRoot ? "" : (isRight ? "|     " : "      ")), false, false);
}

template <typename T>
void BST<T>::preOrder(NodeT<T>* node){
    if(node != nullptr){
        cout<<node->data<<" ";
        preOrder(node->left);
        preOrder(node->right);
    }
}

template <typename T>
void BST<T>::inOrder(NodeT<T>* node){
    if(node != nullptr){
        inOrder(node->left);
        cout<<node->data<<" ";
        inOrder(node->right);
    }
}

template <typename T>
void BST<T>::postOrder(NodeT<T>* node){
    if(node != nullptr){
        postOrder(node->left);
        postOrder(node->right);
        cout<<node->data<<" ";
    }
}

template <typename T>
void BST<T>::levelByLevel(NodeT<T>* node){
    if(node == nullptr) return;
    queue<NodeT<T>*> q;
    q.push(node);
    while(!q.empty()){
        NodeT<T>* curr= q.front();
        q.pop();
        cout<<curr->data<<" ";
        if(curr->left != nullptr) q.push(curr->left);
        if(curr->right != nullptr) q.push(curr->right);
    }
}

template <typename T>
void BST<T>::visit(int method){
    switch(method){
        case 1: preOrder(root); break;
        case 2: inOrder(root); break;
        case 3: postOrder(root); break;
        case 4: levelByLevel(root); break;
        default: cout<<"Opcion no valida."; break;
    }
    cout<<endl;
}

template <typename T>
int BST<T>::heightRec(NodeT<T>* node){
    if(node == nullptr) return 0;
    int leftH= heightRec(node->left);
    int rightH= heightRec(node->right);
    return 1 + (leftH > rightH ? leftH : rightH);
}

template <typename T>
int BST<T>::height(){
    return heightRec(root);
}

template <typename T>
void BST<T>::ancestors(T data){
    if(!find(data)){
        cout<<"El dato no se encuentra en el arbol."<<endl;
        return;
    }
    NodeT<T>* aux= root;
    bool hasAncestors= false;
    while(aux != nullptr && aux->data != data){
        cout<<aux->data<<" ";
        hasAncestors= true;
        if(data < aux->data){
            aux= aux->left;
        }else{
            aux= aux->right;
        }
    }
    if(!hasAncestors){
        cout<<"El nodo es la raiz, no tiene ancestros.";
    }
    cout<<endl;
}

template <typename T>
int BST<T>::whatLevelAmI(T data){
    int level= 1;
    NodeT<T>* aux= root;
    while(aux != nullptr){
        if(aux->data == data) return level;
        level++;
        if(data < aux->data){
            aux= aux->left;
        }else{
            aux= aux->right;
        }
    }
    return -1;
}

template <typename T>
void BST<T>::print(){
    if(root == nullptr){ 
        cout<<"(arbol vacio)"<<endl; 
        return; 
    }
    printTree(root, "", false, true);
}

#endif