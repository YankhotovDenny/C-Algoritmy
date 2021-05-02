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
    Node(Node* _parent, int value) {
        parent = _parent;
        key = value;
    }

    int add(Node* root, int value)
    {
        Node* ph;
        Node* pg;
        if (root->key >= value && root->left != NULL) {
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
            Node* x = new Node(pg, value);
            if (pg->key >= value) pg->left = x;
            if (pg->key < value) pg->right = x;
            while (pg->parent) {
                balance(pg);
                pg = pg->parent;
            }
            return value;
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
            Node* x = new Node(pg, value);
            if (pg->key >= value) pg->left = x;
            if (pg->key < value) pg->right = x;
            while (pg->parent) {
                balance(pg);
                pg = pg->parent;
            }
            return value;
        }
        else {
            Node* x = new Node(root, value);
            if (root->key >= value) root->left = x;
            if (root->key < value) root->right = x;
            return value;
        }
    }


    int check(Node* x) {
        int k = 0, l = 0;
        if (x == NULL) return 0;
        if (x->left == NULL && x->right == NULL) return 1;
        k = check(x->left);
        l = check(x->right);
        if (k > l) return k + 1;
        return l + 1;
    }

    void l_r_s(Node* x) {
        Node* y = x->parent;
        int a = y->key;
        y->key = x->key;
        y->right = x->right;
        Node* o = new Node(y, a);
        o->right = x->left;
        o->left = y->left;
        y->left = o;
    }

    void r_r_s(Node* x) {
        Node* y = x->parent;
        int a = y->key;
        y->key = x->key;
        y->left = x->left;
        Node* o = new Node(y, a);
        o->right = y->right;
        o->left = y->right;
        y->left = o;
    }

    void l_r_b(Node* x) {

    }

    void r_r_b(Node* x) {

    }

    int balance(Node* x) {
        if (abs(check(x) - check(x->parent->left)) > 1)
        {
            l_r_s(x);
            return 1;
        }

        if (abs(check(x) - check(x->parent->right)) > 1)
        {
            r_r_s(x);
            return 1;
        }
    }

    void nodePrint(Node* node, uint32_t d = 0) {
        if (node) {
            nodePrint(node->right, d + 1);
            for (uint32_t l = d; l-- > 0;)putchar('\t');
            std::cout << node->key;
#ifdef DEBUG_PLR
            if (node->parent) std::cout << "p" << node->parent->key;
            if (node->left) std::cout << "l" << node->left->key;
            if (node->right) std::cout << "r" << node->right->key;
#endif
            std::cout << "\n";
            nodePrint(node->left, d + 1);
        }
    }
};

int main() {
    Node* root = new Node(NULL, 0);

    root->add(root, 1);
    root->add(root, 2);
    root->add(root, 3);
    root->nodePrint(root);
    вывод << std::endl;
    вывод << std::endl;
    вывод << std::endl;
    вывод << std::endl;
    root->add(root, 4);
    root->add(root, 5);
    root->add(root, 6);
    root->add(root, 7);
    root->nodePrint(root);
    вывод << std::endl;
    вывод << std::endl;
    вывод << std::endl;
    вывод << std::endl;
}