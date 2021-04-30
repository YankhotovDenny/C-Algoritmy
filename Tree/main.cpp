#include <iostream>
#include <vector>
#include <list>

#define вывод std::cout

class Node
{
public:
    Node* left = NULL;
    Node* right = NULL;
    Node* parent = NULL;
    int key;
    unsigned int height;
    Node(Node* _parent, int value, unsigned int _height) {
        parent = _parent;
        key = value;
        height = _height;
    }

    void add(Node* root, int value)
    {
        Node* ph;
        Node* pg;
        if (root->key >= value && root->left != NULL)
        {
            ph = root->left;
            pg = ph;
            while (ph != NULL)
            {
                if (ph->key >= value)
                {
                    pg = ph;
                    ph = ph->left;
                }
                else {
                    pg = ph;
                    ph = ph->right;
                }
            }
            delete(ph);
            Node* x = new Node(pg, value, (pg->height) + 1);
            if (pg->key >= value) pg->left = x;
            if (pg->key < value) pg->right = x;
        }
        if (root->key < value && root->right != NULL) {
            ph = root->right;
            pg = ph;
            while (ph != NULL)
            {
                if (ph->key >= value)
                {
                    pg = ph;
                    ph = ph->left;
                }
                else {
                    pg = ph;
                    ph = ph->right;
                }
            }
            delete(ph);
            Node* x = new Node(pg, value, (pg->height) + 1);
            if (pg->key >= value) pg->left = x;
            if (pg->key < value) pg->right = x;
        }
        else {
            Node* x = new Node(root, value, (root->height) + 1);
            if (root->key >= value) root->left = x;
            if (root->key < value) root->right = x;
        }
    }
};

int main() {
    int value = 3;
    Node* root = new Node(NULL, value, 0);
    root->add(root, 6);
    root->add(root, 8);
    root->add(root, 5);
    root->add(root, -1);
    вывод << root->key;
    вывод << std::endl;
    вывод << root->right->key;
    вывод << std::endl;
    вывод << root->right->right->key;
    вывод << std::endl;
    вывод << root->right->right->parent->parent->key;
    вывод << std::endl;
    вывод << root->height << ' ' << root->right->height << ' ' << root->right->right->height << ' ';
}
