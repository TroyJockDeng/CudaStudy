#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

template<class Key, class Value>
class BST{
public:
    BST(){
        root = NULL;
        count = 0;
    }

    ~BST(){
        ;
    }

    int size(){
        return count;
    }

    void insert(Key key, Value value){
        root  = _insert(root, key, value);
    }

    void preOrder(){
        _preOrder(root);
    }

    void inOrder(){
        _inOrder(root);
    }

    pair<Key, Value>* minimum(){
        if(!root)
            return NULL;
        Node* node = _minimum(root);
        return new pair<Key, Value>((make_pair(node->key, node->value)));
    }

    pair<Key, Value>* maximum(){
        if(!root)
            return NULL;
        Node* node = _maximum(root);
        return new pair<Key, Value>((make_pair(node->key, node->value)));
    }

    void remove(Key key){
        root = _remove(root, key);
    }

    void removeMin(){
        _removeMin(root);
    }
    
    void removeMax(){
        _removeMax(root);
    }

    // Value* search(Key key){
    //     _search(root, key);
    // }

private:
    struct Node{
        Key key;
        Value value;
        Node* left;
        Node* right;

        Node(Key key, Value value){
            this->key = key;
            this->value = value;
            this->left = this->right = NULL;
        }

        Node(Node* node){
            this->key = node->key;
            this->value = node->value;
            this->left = node->left;
            this->right = node->right;
        }
    };

    Node* _insert(Node* node, Key key, Value value);
    Node* _minimum(Node* node);
    Node* _maximum(Node* node);

    Node* _search(Node* node, Key key);
    void _preOrder(Node* node);
    void _inOrder(Node* node);

    Node* _removeMin(Node* node);
    Node* _removeMax(Node* node);
    Node* _remove(Node* node, Key k);

    Node* root;
    int count;
};

template<typename Key, typename Value>
typename BST<Key, Value>::Node* BST<Key, Value>::_insert(BST<Key, Value>::Node* node, Key key, Value value){
    if (!node){
        return new BST<Key, Value>::Node(key, value);
        this->count++;
    }
    if (key == node->key)
        node->value = value;
    else if(key < node->key)
        node->left = _insert(node->left, key, value);
    else
        node->right = _insert(node->right, key, value);
    return node;
}

template<class Key, class Value>
void BST<Key, Value>::_preOrder(Node* node){
    if (!node)
        return;
    cout << "key: " << node->key << ", value: " << node->value << endl;
    _preOrder(node->left);
    _preOrder(node->right);
}

template<class Key, class Value>
void BST<Key, Value>::_inOrder(Node* node){
    if (!node)
        return;
    _inOrder(node->left);
    cout << "key: " << node->key << ", value: " << node->value << endl;
    _inOrder(node->right);
}

template<class Key, class Value>
typename BST<Key,Value>::Node*  BST<Key, Value>::_minimum(Node* node){
    if(node->left)
        return _minimum(node->left);
    else 
        return node;
}

template<class Key, class Value>
typename BST<Key,Value>::Node*  BST<Key, Value>::_maximum(Node* node){
    if(node->right)
        return _maximum(node->right);
    else 
        return node;
}

template<class Key, class Value>
typename BST<Key, Value>::Node* BST<Key, Value>::_removeMin(Node* node){
    if (!node)
        return NULL;
    if (!node->left){
        Node* rightNode = node->right;
        delete node;
        return rightNode;
    }

    node->left = _removeMin(node->left);
}

template<class Key, class Value>
typename BST<Key, Value>::Node* BST<Key, Value>::_removeMax(Node* node){
    if (!node)
        return NULL;
    if (!node->right){
        Node* leftNode = node->left;
        delete node;
        return leftNode;
    }

    node->right = _removeMin(node->right);
}

template<class Key, class Value>
typename BST<Key, Value>::Node* BST<Key, Value>::_remove(Node* node, Key key){
    if(!node)
        return NULL;

    if (key == node->key){
        if (!node->left){
            Node* rightNode = node->right;
            delete node;
            return rightNode;
        }else if (!node->right){
            Node* leftNode = node->left;
            delete node;
            return leftNode;
        }else{
            Node* maxNode = new Node(_maximum(node->left));
            Node* leftNode = _removeMax(node->left);
            maxNode->left = leftNode;
            maxNode->right = node->right;
            delete node;
            return maxNode;
        }
    }
    else if (key < node->key)
        node->left = _remove(node->left, key);
    else if (key > node->key)
        node->right = _remove(node->right, key);    
    return node;
}
int main(){
    BST<int, int> bst;
    bst.insert(8, 1);
    bst.insert(3, 1);
    bst.insert(7, 1);
    bst.insert(6, 2);
    bst.insert(5, 1);
    bst.insert(10, 13);

    bst.inOrder();
    cout << endl;

    auto minimum = bst.minimum();
    cout << "mmin, key: " << minimum->first << ", value: " << minimum->second << endl;
    auto maximum = bst.maximum();
    cout << "max, key: " << maximum->first << ", value: " << maximum->second << endl;

    // bst.removeMin();
    // bst.removeMax();
    // bst.removeMax();
    // remove
    bst.remove(7);
    bst.remove(3);
    bst.remove(6);
    cout << endl;
    bst.inOrder();

    string s =" asf asdasd";
    for (auto x: s){
        cout << x;
    }

    cout << endl;
    vector<vector<bool>> been;
    been = vector<vector<bool>>(5, vector<bool>(3, true));
    cout << been[0][0] << endl;
}
