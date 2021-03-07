#include <iostream>
using std::cin;
using std::cout;
using std::endl;


typedef struct Node {
    int value;
    struct Node* next;
} Node;

void push_left(Node** head, int value) {
    Node* tmp = (Node*)malloc(sizeof(Node));
    tmp->value = value;
    tmp->next = (*head);
    (*head) = tmp;
}

void clear_list(Node** head) {
    while (*head != NULL) {
        Node* prev = NULL;
        prev = (*head);
        (*head) = (*head)->next;
        free(prev);
    }
    free(*head);
}


int pop(Node** head, int index) {
    if (head == NULL) {
        exit(-1);
    }
    if (index == 0) {
        Node* prev = NULL;
        int val;
        prev = (*head);
        val = prev->value;
        (*head) = (*head)->next;
        free(prev);
        return val;
    }
    else {
        Node* tmp = *head;
        Node* elm = NULL;
        for (int i = 0; i < index - 1 && *head; i++) {
            tmp = tmp->next;
        }
        if (tmp != NULL) {
            elm = tmp->next;
            int val = elm->value;

            tmp->next = elm->next;
            free(elm);
            return val;
        }
        else {
            return NULL;
        }
    }
}

void remove(Node** head, int value) {
    if (head == NULL) {
        exit(-1);
    }
    if ((*head)->value == value) {
        Node* prev = (*head)->next;
       free(*head);
       *head = prev;
    }
    else {
        Node* tmp = *head;
        Node* elm = NULL;
        for (int i = 0; tmp->next != NULL; i++) {
            if (tmp->next->value == value)
            {
                break;
            }
            tmp = tmp->next;
        }
        if (tmp->next != NULL)
        {
            elm = tmp->next;
            int val = elm->value;

            tmp->next = elm->next;
            free(elm);
        }
    }
}

void remove_all(Node** head, int value) {
    int g = 0;
    Node* tmp = *head;
    for (int i = 0; tmp != NULL; i++)
    {
        if (tmp->value == value) {
            g++;
        }
        tmp = tmp->next;
    }
    for (int i = 0; i < g; i++)
    {
        remove(head, value);
    }
}

void replace_all(Node* head, int old_value, int new_) {
    int g = 0;
    Node* tmh = head;
    for (int i = 0; tmh != NULL; i++)
    {
        if (tmh->value == old_value)
        {
            tmh->value = new_;
        }
        tmh = tmh->next;
    }
}

int unique(Node* head) {
    Node* tmp = head;
    Node* tmh = head;
    int h = 0, n = 0;
    for (int i = 0; tmp != NULL; i++)
    {
        for (int j = 0; tmh != NULL; j++)
        {
            if (tmh->value == tmp->value) {
                h++;
            }
            tmh = tmh->next;
        }
        if (h == 1) {
            n++;
        }
        tmp = tmp->next;
        h = 0;
        tmh = head;
    }
    return n;
}

void reverse(Node** head) {
    Node* tmp = NULL;
    for (int i = 0; *head != NULL; i++)
    {
        push_left(&tmp, (*head)->value);
        *head = (*head)->next;
    }
    free(*head);
    *head = tmp;
}

void print_list(Node* head) {
    for (Node* curr = head; curr != nullptr; curr = curr->next) {
        cout << curr->value << ' ';
    }
    cout << endl;
}

int main() {
    Node* head;
    head = NULL;
    for (int i = 0; i < 6; ++i) {
        push_left(&head, i);
    }   
    push_left(&head, 0);
    cout << unique(head) << endl;
    print_list(head);
    reverse(&head);
    pop(&head, 6);
    print_list(head);
    cout << pop(&head, 2) << endl;
    print_list(head);
    replace_all(head, 0, 6);
    print_list(head);
    clear_list(&head);
    for (int i = 0; i < 6; ++i) {
        push_left(&head, 6);
    }
    print_list(head);
    cout << unique(head) << endl;
    remove_all(&head, 6);
    print_list(head);
    clear_list(&head);
    pop(&head, 2);
    reverse(&head);
    return 0;
}