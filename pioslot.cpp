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

