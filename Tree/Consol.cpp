#include <iostream>
#include <vector>
#include <cstdlib>
#include <chrono>
#include <fstream>


#define вывод std::cout

static std::vector<int> head;

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
        add_to_vector(value);
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
                if (balance(pg)) {
                    rebuild(root);
                    return value;
                }
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
                if (balance(pg)) {
                    rebuild(root);
                    return value;
                }
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

    int add_2(Node* root, int value)
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
            return value;
        }
        else {
            Node* x = new Node(root, value);
            if (root->key >= value) root->left = x;
            if (root->key < value) root->right = x;
            return value;
        }
    }

    void rebuild(Node* root) {
        if (root->left) root->left = NULL;
        if (root->right) root->right = NULL;
        root->key = head[head.size() / 2 - 1];
        defus(head, root);
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

    bool balance(Node* x) {
        if (x->parent) {
            if (abs(check(x) - check(x->parent->left)) > 1)
            {
                return true;
            }
            if (abs(check(x) - check(x->parent->right)) > 1)
            {
                return true;
            }
        }
        return false;
    }

    bool add_to_vector(int a) {
        for (int i = 0; i < head.size(); i++)
        {
            if (head[i] > a) {
                head.insert(head.begin() + i, a);
                return true;
            }
        }
    }

    bool defus(std::vector<int> h, Node* root) {
        int a = h.size() / 2 - 1;
        if (a == -1)
        {
            return false;
        }
        std::vector<int> h1(h.begin(), h.begin() + a + 1);
        std::vector<int> h2(h.begin() + a + 1, h.end());
        if (h[h.size() / 2 - 1] != head[head.size() / 2 - 1]) root->add_2(root, h[h.size() / 2 - 1]);
        defus(h1, root);
        defus(h2, root);
    }

    int delete_value(Node* root, int value) {
        if (search(root, value))
        {
            for (int i = 0; i < head.size(); i++)
            {
                if (head[i] == value)
                {
                    head.erase(head.begin() + i);
                }
            }
            rebuild(root);
        }
        return NULL;
    }

    Node* search(Node* root, int value) {
        Node* ph;
        Node* pg;
        if (root->key == value) return root;
        if (root->key >= value && root->left != NULL) {
            ph = root->left;
            pg = ph;
            while (ph != NULL)
            {

                if (ph->key == value) {
                    return ph;
                }
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
            return NULL;
        }
        if (root->key < value && root->right != NULL) {
            ph = root->right;
            pg = ph;
            while (ph != NULL)
            {
                if (ph->key == value) {
                    return ph;
                }
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
            return NULL;
        }
        return NULL;
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
    head.push_back(999999);
    std::ofstream out;
    out.open("D:\\TreeSearchTrue.txt");
    for (int i = 10; i < 1000; i++)
    {
        root->add(root, i);
        auto start = std::chrono::system_clock::now();
        root->search(root, -1); // никогда не находит
        auto end = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed_seconds = end - start;
        std::cout << "elapsed time: " << elapsed_seconds.count() * pow(10, 6) << std::endl;
        if (out.is_open()) out << i << "-" << elapsed_seconds.count() * pow(10, 6) << std::endl;
    }
    root->nodePrint(root);
}