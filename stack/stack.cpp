#include <iostream>

struct Item
{
    int value;
    Item* previous;
};

class Stack
{
private:
    Item* top;
    unsigned int size;
    void clear(unsigned int);
    
public:
    Stack();
    Stack(Stack*);
    void set(int, unsigned int);
    int get(unsigned int);
    ~Stack();
    void push(const int);
    int pop();
    unsigned int getSize();
    void clear();
    void sort();
    int back();

};

int main()
{
    Stack stack1;
    stack1.push(1);
    stack1.push(2);
    stack1.push(3);
    stack1.push(4);
    stack1.push(5);
    stack1.push(6);
    Stack st(&stack1);
    stack1.set(stack1.get(0),3);
    
    
     std::cout << stack1.get(3) << "\n";
    stack1.sort();
    while (st.getSize())
    {
        std::cout << st.pop() << " ";
    }
    std::cout << "\n";
    while (stack1.getSize())
    {
        std::cout << stack1.pop() << " ";
    }
}

Stack::Stack(): top(nullptr), size(0){}

Stack::Stack(Stack* baseStack)
{
    size = baseStack->getSize();
    top = nullptr;
    if (size)
    {
        Item* itemFromSource = baseStack->top;
        Item* itemPrevious = new Item();
        itemPrevious->previous = nullptr;
        itemPrevious->value = itemFromSource->value;
        top = itemPrevious;
        for (unsigned int i = size - 1; i > 0; --i)
        {
            itemFromSource = itemFromSource->previous;
            Item* itemCurrent = new Item();
            itemCurrent->previous = nullptr;
            itemCurrent->value = itemFromSource->value;
            itemPrevious->previous = itemCurrent;;
            itemPrevious = itemCurrent;
        }
    }
}

void Stack::push(const int value)
{
    Item* newItem = new Item();
    newItem->previous = top;
    newItem->value = value;
    top = newItem;
    size++;
}

int Stack::pop()
{
    Item* lastItem = top;
    top = lastItem->previous;
    int lastvalue = lastItem->value;
    delete lastItem;
    size--;
    return lastvalue;
}

int Stack::back()
{
    return top->value;
}

unsigned int Stack::getSize()
{
    return size;
}

void Stack::clear()
{
    Item* currentItem;
    for (unsigned int i = size; i > 0; --i)
    {
        currentItem = top;
        top = currentItem->previous;
        delete currentItem;
    }
    size = 0;
}

void Stack::clear(unsigned int index)
{
    Item* currentItem;
    for (unsigned int i = 0; i < index; i++)
    {
        currentItem = top;
        top = currentItem->previous;
        delete currentItem;
    }
    this->size -= index;
}

int Stack::get(unsigned int index)
{
    
    Stack temp(this);
    int result = 0;
    for (unsigned int i = 0; i < index + 1; ++i)
    {
        result = temp.pop();
    }
    return result;

}

void Stack::set(int value, unsigned int index)
{

    Stack temp(this);
    clear(index);
    top->value = value;
    for (unsigned int i = index; i > 0; --i)
    {
        push(temp.get(i - 1));
    }
}

void Stack::sort()
{
    int s = size;
    int tmp = 0;
    for (int i = 0; i < s; i++)
    {
        for (int j = s - 1; j >= i+1;j--)
        {
            if (get(j) < get(j - 1))
            {
                tmp = get(j);
                set(get(j - 1), j);
                set(tmp, j - 1);
            }
        }
    }
   
    //void merge(int* a, int n)
    //{
    
    /*int n = size;
    int mid = n / 2; // находим середину сортируемой последовательности
    if (n % 2 == 1)
        mid++;
    int h = 1; // шаг
    // выделяем память под формируемую последовательность
    Stack c;
    for (int i = 0; i < size; i++)
    {
        c.push(0);
    }
    int step;
    while (h < n)
    {
        step = h;
        int i = 0;   // индекс первого пути
        int j = mid; // индекс второго пути
        int k = 0;   // индекс элемента в результирующей последовательности
        while (step <= mid)
        {
            while ((i < step) && (j < n) && (j < (mid + step)))
            { // пока не дошли до конца пути
              // заполняем следующий элемент формируемой последовательности
              // меньшим из двух просматриваемых
                if (get(i) < get(j))
                {
                    //c[k] = a[i];
                    c.set(get(i), k);
                    i++; k++;
                }
                else {
                    //c[k] = a[j];
                    c.set(get(j), k);
                    j++; k++;
                }
            }
            while (i < step)
            { // переписываем оставшиеся элементы первого пути (если второй кончился раньше)
                //c[k] = a[i];
                c.set(get(i), k);
                i++; k++;
            }
            while ((j < (mid + step)) && (j < n))
            {  // переписываем оставшиеся элементы второго пути (если первый кончился раньше)
                //c[k] = a[j];
                c.set(get(j), k);
                j++; k++;
            }
            step = step + h; // переходим к следующему этапу
        }
        h = h * 2;

        // Переносим упорядоченную последовательность (промежуточный вар`иант) в исходный массив
        for (i = 0; i < n; i++)
            set(c.get(i), i);
            //a[i] = c[i];

    }
    // }
    */
}


Stack::~Stack()
{
    clear();
}
