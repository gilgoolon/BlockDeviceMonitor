#include "auto_lock.hpp"
#include "../../exceptions.hpp"
#include "../logging/logger.hpp"

Autos::AutoLock::AutoLock(std::shared_ptr<std::mutex> mutex)
    : _mutex(std::move(mutex))
{
    _mutex->lock();
}

Autos::AutoLock::~AutoLock()
{
    try {
        _mutex->unlock();
    } catch (const ErrnoException& ex) {
        WARNING(ex.what())
    }
}