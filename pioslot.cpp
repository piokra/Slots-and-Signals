#include "pioslot.h"

Slot::Slot(std::function<void(int,void*)> func)
{
    m_function=func;
}

void Slot::execute(int argc, void* argv)
{
    m_function(argc, argv);

}

Slot::~Slot()
{

}

void Slot::addReceiver(Signal* sig)
{
    sig->addSlot(this);
    m_connected++;
}


void Slot::removeReceiver()
{
    m_connected--;
    if(m_connected<=0)
    {
        delete this;
    }
}

