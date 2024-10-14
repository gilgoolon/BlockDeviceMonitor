#include "auto_lock.hpp"

autos::AutoLock::AutoLock(std::shared_ptr<std::mutex> mutex)
    : _mutex(std::move(mutex))
{
    _mutex->lock();
}

autos::AutoLock::~AutoLock()
{
    try
    {
        _mutex->unlock();
    }
    catch (...)
    {
    }
}