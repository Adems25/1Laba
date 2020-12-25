#include <iostream>
#include <stdexcept>

using namespace std;

class List
{
    class Node
    {
    public:
        int key;
        Node* next;
        Node(int Key)
        {
            key = Key;
            next = nullptr;
        }
    };
    Node* head;
    Node* last;
    size_t size;
public:
    List()
    {
        head = nullptr;
        last = nullptr;
        size = 0;
    }
    bool isEmpty()
    {
        return (size == 0);
    }
    size_t get_size()
    {
        return size;
    }
    void push_back(int Key)
    {
        Node* Include = new Node(Key);
        if (isEmpty())
            head = Include;
        else
            last->next = Include;
        last = Include;
        size++;
    }
    void push_front(int Key)
    {
        Node* Include = new Node(Key);
        if (isEmpty())
            last = Include;
        else
            Include->next = head;
        head = Include;
        size++;
    }
    void pop_back()
    {
        if (isEmpty())
            throw runtime_error("List is empty\n");
        if (head == last)
        {
            delete head;
            head = nullptr;
            last = nullptr;
        }
        else
        {
            Node* Cur = head;
            while (Cur->next != last)
                Cur = Cur->next;
            Cur->next = nullptr;
            delete last;
            last = Cur;
        }
        size--;
    }
    void pop_front()
    {
        if (isEmpty())
            throw runtime_error("List is empty\n");
        if (head == last)
        {
            delete head;
            head = nullptr;
            last = nullptr;
        }
        else
        {
            Node* NewHead = head->next;
            delete head;
            head = NewHead;
        }
        size--;
    }
    void insert(size_t index, int Key)
    {
        if (index >= size)
            throw out_of_range("List is too short\n");
        if (index == 0)
            push_front(Key);
        else
        {
            Node* Include = new Node(Key);
            Node* Cur = head;
            Node* Prev = nullptr;
            for (int i = 0;i < index;i++)
            {
                Prev = Cur;
                Cur = Cur->next;
            }
            Prev->next = Include;
            Include->next = Cur;
            size++;
        }
    }
    int at(size_t index)
    {
        if (index >= size)
            throw out_of_range("List is too short\n");
        if (index == 0)
            return head->key;
        else if (index == (size - 1))
            return last->key;
        else
        {
            Node* Cur = head;
            for (int i = 0;i < index;i++)
                Cur = Cur->next;
            return Cur->key;
        }
    }
    void remove(size_t index)
    {
        if (index >= size)
            throw out_of_range("List is too short\n");
        if (index == 0)
            pop_front();
        else if (index == (size - 1))
            pop_back();
        else
        {
            Node* Cur = head;
            Node* Prev = nullptr;
            for (int i = 0;i < index;i++)
            {
                Prev = Cur;
                Cur = Cur->next;
            }
            Prev->next = Cur->next;
            delete Cur;
            size--;
        }
    }
    void set(size_t index, int Key)
    {
        if (index >= size)
            throw out_of_range("List is too short\n");
        else
        {
            insert(index, Key);
            remove(index + 1);
        }
    }
    void reverse()
    {
        if (isEmpty())
            throw runtime_error("List is empty\n");
        if (size > 1)
        {
            Node* Cur = head;
            Node* Prev = nullptr;
            Node* Next = nullptr;
            while (Cur != nullptr)
            {
                Next = Cur->next;
                Cur->next = Prev;
                Prev = Cur;
                Cur = Next;
            }
            Cur = head;
            head = last;
            last = Cur;
        }
    }
    void print_to_console()
    {
        if (isEmpty())
            throw runtime_error("List is empty\n");
        Node* Cur = head;
        while (Cur != nullptr)
        {
            cout << Cur->key << ' ';
            Cur = Cur->next;
        }
        cout << endl;
    }
    void clear()
    {
        while (!isEmpty())
            pop_front();
    }
    ~List()
    {
        clear();
    }
};

int main()
{
    List L;
    L.push_back(1);
    L.push_back(3);
    L.insert(1, 2);
    L.print_to_console();
    L.reverse();
    L.print_to_console();
    L.remove(1);
    L.print_to_console();
}