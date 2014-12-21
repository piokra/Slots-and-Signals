#ifndef SIGNAL_H
#define SIGNAL_H

#include <vector>

#include "piofunctionwrapper.h"

#include "pioslot.h"
#include "piosignals.h"
class Slot;
class Signals;

class Signal
{
public:
    friend class Signals;
    friend class Slot;

    void cemit(int, void*);
    void removeEmitter(Signal*&);


protected:
    void addSlot(Slot*);
    void addEmitter();


    Signal(int);
    ~Signal();

private:
    int m_id;
    int m_connected;
    std::vector<Slot*> m_slots;


};

#endif // SIGNAL_H
