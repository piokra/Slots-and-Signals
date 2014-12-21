#include "piosignal.h"

Signal::Signal(int id)
{
    m_id=id;

    if(id==-1)
    {
        // give a random id;
    }

}


void Signal::addSlot(Slot* val)
{
    m_slots.push_back(val);
}

void Signal::cemit(int argc, void * argv)
{
    for(unsigned i=0; i<m_slots.size(); i++)
    {
        m_slots.at(i)->execute(argc,argv);
    }
}

Signal::~Signal()
{

}

