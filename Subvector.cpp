#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>
#include <sstream>


using namespace std;

struct  subvector {
    int* mas;
    unsigned int top;
    unsigned int capacity;
};

bool init(subvector* q) {
    q->capacity = 2;
    q->top = 0;
    q->mas = (int*)malloc(q->capacity * sizeof(int));
    return q;
}

bool push_back(subvector* q, int d)
{
    if (q->top >= q->capacity)
    {
        q->capacity *= 2;
        q->mas = (int*)realloc(q->mas, q->capacity * sizeof(int));
    }
    q->mas[q->top++] = d;
    return true;
}

int pop_back(subvector* q)
{
    int a = q->mas[q->top];
    q->top = q->top--;
    return a;
}

bool resize(subvector* q, unsigned int new_capacity)
{
    if (q->top > new_capacity)
    {
        return false;
    }
    else
    {
        q->capacity = new_capacity;
        return true;
    }
}

void shrink_to_fit(subvector* q)
{
    q->capacity = q->top;
    q->mas = (int*)realloc(q->mas, q->capacity * sizeof(int));
}

void clear(subvector* q)
{
    q->top = 0;
}

void destructor(subvector* q)
{
    clear(q);
    init(q);
}

bool init_from_file(subvector* q, const char* filename)
{
    string line;
    destructor(q);

    ifstream in(filename); // îêðûâàåì ôàéë äëÿ ÷òåíèÿ
    if (in.is_open())
    {
        getline(in, line); // ïðåäïîãàãàþ ÷òî âñå äàííûå çàïèñàíû â îäíó ñòðî÷êó
        istringstream iss(line);
        vector<string> v((istream_iterator<string>(iss)), istream_iterator<string>());
        for (int i = 0; i < size(v); i++)
        {
            push_back(q, stoi(v[i]));
        }
    }
    in.close();
    return q->mas;
}

void print_subvector(subvector* head) {
    for (int i = 0; i < head->top; i++) {
        cout << head->mas[i] << ' ';
    }
    cout << endl;
}

int main()
{
    subvector h;
    init(&h);
    push_back(&h, 1);
    push_back(&h, 1);
    push_back(&h, 1);
    
    pop_back(&h);
    push_back(&h, 5);
    print_subvector(&h);
    
    destructor(&h);
    push_back(&h, 5);
    print_subvector(&h);
    
    clear(&h);
    push_back(&h, 4);
    print_subvector(&h);
    
    destructor(&h);
    for (int i = 0; i < 9; i++)
    {
        push_back(&h, i * i);
    }
    print_subvector(&h);

    const char * y = "txt.txt";
    init_from_file(&h, y);
    print_subvector(&h);
    return 0;
}
