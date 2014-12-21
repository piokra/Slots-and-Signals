#ifndef FUNCTIONWRAPPER
#define FUNCTIONWRAPPER

#include <functional>


template <class T>
std::function<void(int, void*)> functionwrapper(T *member, void(T::*funcptr)(int argc, void* argv))
{
    std::function<void(int, void*)> ret;
    ret = [=](int argc, void* argv)->void{ (member->*funcptr)(argc, argv);
    };
    return ret;
}

template <class T>
std::function<void(int, void*)> functionwrapper(T* member, void(T::*funcptr)(void))
{
    std::function<void(int, void*)> ret;
    ret =[=](int,void*)->void{ member->*funcptr();};
    return ret;

}
template <class T>
std::function<void(int,void*)> functionwrapper(void (T::*funcptr)(int, void *))
{
    std::function<void(int,void*)> ret =[=](int argc,void* argv)->void { funcptr(argc,argv); };
    return ret;
}
template <class T>
std::function<void(int,void*)> functionwrapper(void (T::*funcptr)())
{
    std::function<void(int,void*)> ret =[=](int argc,void* argv)->void { funcptr(); };
    return ret;
}

typedef void (*function_t)(int, void*);

inline function_t topointer(std::function<void(int,void*)> inp)
{
    function_t* ret = inp.target<function_t>();
    return *ret;
}





#endif // FUNCTIONWRAPPER

