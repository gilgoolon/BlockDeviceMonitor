#include "auto_lock.hpp"

AutoLock::AutoLock(std::shared_ptr<std::mutex> mutex)
    : _mutex(std::move(mutex))
{
    _mutex->lock();
}

AutoLock::~AutoLock()
{
    _mutex->unlock();
}