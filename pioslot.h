#ifndef SLOT_H
#define SLOT_H


#include "piofunctionwrapper.h"
#include "piosignal.h"

class Signal;

class Slot
{
public:
    Slot(std::function<void(int, void *)> func);
    void execute(int, void*);
    ~Slot();
private:
    std::function<void(int, void*)> m_function;

};

#endif // SLOT_H
