#ifndef SLOT_H
#define SLOT_H


#include "piofunctionwrapper.h"
#include "piosignal.h"

class Signal;

class Slot
{
    friend class MainWindow;
    friend class Signal;
public:
    Slot(std::function<void(int, void *)> func);
    void execute(int, void*);
    void addReceiver(Signal*);
protected:
    void removeReceiver();
    ~Slot();
private:
    int m_connected;
    std::vector<Signal*> m_parents;
    std::function<void(int, void*)> m_function;

};

#endif // SLOT_H
