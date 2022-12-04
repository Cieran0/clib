#include<stdlib.h>

#define STACK template <typename stackType> stack<stackType>
#define STACKT(type) template <typename stackType> type stack<stackType>
#define DEFAULT_SIZE 8192

namespace clib {
    template <typename stackType>
    class stack
    {
    private:
        stackType* start;
        stackType* current;
        size_t size;
        bool empty;

    public:
        stack(size_t size);
        stack();
        ~stack();
        void push(stackType item);
        stackType pop();
        stackType top();
    };

    STACKT(stackType)::pop() {
        if(empty) return 0;
        stackType st =  *(this->current);
        if(current == start) empty = true;
        else current--;
        return st;
    }

    STACKT(stackType)::top() {
        if(empty) return 0;
        return *(this->current);
    }

    STACKT(void)::push(stackType item) {
        if(!empty) {
            current++;
        }
        empty = false;
        *current = item;
    }

    STACK::stack(size_t size)
    {
        this->size = size;
        this->start = (stackType*)malloc(sizeof(stackType)*this->size);
        this->current = this->start;
        this->empty = true;
    }
    
    STACK::stack()
    {
        stack(DEFAULT_SIZE);

    }
    
    STACK::~stack()
    {
        free(start);
    }
    
}
