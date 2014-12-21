#ifndef SIGNAL_H
#define SIGNAL_H

#include <vector>

#include "piofunctionwrapper.h"

#include "pioslot.h"

class Slot;

class Signal
{
public:
    Signal(int=-1);
    void addSlot(Slot*);
    void cemit(int, void*);

    ~Signal();
private:
    int m_id;
    std::vector<Slot*> m_slots;


};

#endif // SIGNAL_H
