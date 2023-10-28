#include <iostream>
#include <random>
#include <algorithm>

#define AR 1000000
//const int arrsize = 1000000; // редактирование размера дерева
class AVLTree { //класс авл-дерева
private:
    struct Node {
        int key;
        int height;
        Node* left;
        Node* right;

        Node(int k) : key(k), height(1), left(nullptr), right(nullptr) {}
    };

    Node* root;

    int height(Node* node) {
        return (node) ? node->height : 0;
    }

    int balanceFactor(Node* node) {
        return height(node->right) - height(node->left);
    }

    void updateHeight(Node* node) {
        node->height = 1 + std::max(height(node->left), height(node->right));
    }

    Node* rotateRight(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        x->right = y;
        y->left = T2;

        updateHeight(y);
        updateHeight(x);

        return x;
    }

    Node* rotateLeft(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        updateHeight(x);
        updateHeight(y);

        return y;
    }

    Node* balance(Node* node) {
        updateHeight(node);

        int bf = balanceFactor(node);

        if (bf > 1) {
            if (balanceFactor(node->right) < 0) {
                node->right = rotateRight(node->right);
            }
            return rotateLeft(node);
        }
        if (bf < -1) {
            if (balanceFactor(node->left) > 0) {
                node->left = rotateLeft(node->left);
            }
            return rotateRight(node);
        }
        return node;
    }

    Node* insert(Node* node, int key) {
        if (!node) {
            return new Node(key);
        }

        if (key < node->key) {
            node->left = insert(node->left, key);
        }
        else if (key > node->key) {
            node->right = insert(node->right, key);
        }
        else {
            return node;
        }

        return balance(node);
    }

    Node* findMinValueNode(Node* node) {
        Node* current = node;
        while (current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

    Node* remove(Node* node, int key) {
        if (!node) {
            return node;
        }

        if (key < node->key) {
            node->left = remove(node->left, key);
        }
        else if (key > node->key) {
            node->right = remove(node->right, key);
        }
        else {
            if (!node->left || !node->right) {
                Node* temp = (node->left) ? node->left : node->right;
                if (!temp) {
                    temp = node;
                    node = nullptr;
                }
                else {
                    *node = *temp;
                }
                delete temp;
            }
            else {
                Node* temp = findMinValueNode(node->right);
                node->key = temp->key;
                node->right = remove(node->right, temp->key);
            }
        }

        if (!node) {
            return node;
        }

        return balance(node);
    }

    void inOrderTraversal(Node* node) {
        if (node) {
            inOrderTraversal(node->left);
            std::cout << node->key << " ";
            inOrderTraversal(node->right);
        }
    }

    void printAVL(Node* root, int n) {
        if (root != NULL) {
            printAVL(root->left, n + 5);
            for (int i = 0; i < n; i++)
            {
                std::cout << " ";
            }
            std::cout << root->key << "\n";
            printAVL(root->right, n + 5);
        }
    }

    Node* maketree_search(Node* root, int* arr) {
        if (AR == 0) {
            return nullptr;
        }
        for (int i = 0; i < AR; i++){
            int key = arr[i];
            int arr_ind = i + 1;
            if (arr_ind % 5000 == 0){
                std::cout << "Iteration: " << arr_ind << std::endl;
            }
            insert(key);
        }
        return root;
    }

public:
    AVLTree() : root(nullptr) {}

    void insert(int key) {
        root = insert(root, key);
    }

    void remove(int key) {
        root = remove(root, key);
    }

    void inOrder() {
        inOrderTraversal(root);
        std::cout << std::endl;
    }
    int n = 0;

    void printAVL() {
        if (root != NULL) {
            printAVL(root->right, n + 5);
            for (int i = 0; i < n; i++)
            {
                std::cout << " ";
            }
            std::cout << root->key << "\n";
            printAVL(root->left, n + 5);
        }
    }

    void make_tree(int* arr){
        maketree_search(root, arr);
    }
};

int* generateRandomNumbers(int* arr, int arrsize) {
    for (int i = 0; i < arrsize; i++) {
        arr[i] = i;
    }
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(arr, arr + arrsize, g);
    return arr;
}


int main() {
    int* arr = new int[AR];
    generateRandomNumbers(arr, AR + 1);
    AVLTree avlTree;
    avlTree.make_tree(arr);  
    avlTree.insert(1000001); // - добавление элемента
    avlTree.remove(1000001); // - удаление элемента
    //avlTree.printAVL(); - вывод дерева в красивом виде
    return 0;
}
