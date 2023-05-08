#include <iostream>
#include <string>
#include<queue>
#include<stack>

using namespace std;

struct Node {
    string data;
    Node* next;
};

// функция добавления элемента в стек
void push(Node** head_ref, string new_data) {
    Node* new_node = new Node;
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

// функция удаления элемента из стека
string pop(Node** head_ref) {
    if ((*head_ref) == NULL) {
        return "";
    }
    string res = (*head_ref)->data;
    Node* temp = (*head_ref);
    (*head_ref) = (*head_ref)->next;
    delete temp;
    return res;
}

// функция разделения стека на два путем проверки длины каждого элемента
void splitStack(Node** head_ref, Node** short_ref, Node** long_ref) {
    while (*head_ref != NULL) {
        string word = pop(head_ref);
        if (word.length() < 7) { //<7 следовательно короткое
            push(short_ref, word);
        }
        else {// инача >=7 следовательно длинное
            push(long_ref, word);
        }
    }
}

// функция вывода элементов стека
void printStack(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "RUSSIAN");
    Node* head = NULL;
    push(&head, "степан");
    push(&head, "доронин");
    push(&head, "пиво");
    push(&head, "алгоритмизация");
    push(&head, "мама");
    push(&head, "здраствуйте");
    push(&head, "хочу");
    push(&head, "десять");
    push(&head, "баллов");
    push(&head, "программирование");

    Node* short_stack = NULL;
    Node* long_stack = NULL;
    splitStack(&head, &short_stack, &long_stack);


    cout << "Список коротких слов: ";//< 7 букв
    printStack(short_stack);
    cout << "Список длиных слов: ";//>= 7 букв
    printStack(long_stack);
}
