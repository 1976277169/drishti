/**
  @file   drishti/ManagerImpl.h
  @author David Hirvonen
  @brief  Private header for the Manager class.

  \copyright Copyright 2014-2016 Elucideye, Inc. All rights reserved.
  \license{This project is released under the 3 Clause BSD License.}

*/

#ifndef DRISHTI_DRISHTI_MANAGER_IMPL_H
#define DRISHTI_DRISHTI_MANAGER_IMPL_H 1

#include "drishti/Manager.hpp"

#include "drishti/hci/FaceFinder.h"
#include "drishti/core/make_unique.h"
#include "drishti/core/Logger.h" // spdlog::logger
#include "drishti/sensor/Sensor.h"

#include "thread_pool/thread_pool.hpp"

#define DRISHTI_LOGGER_NAME "drishti"

_DRISHTI_SDK_BEGIN

class Manager::Impl
{
public:
    Impl(const drishti::sensor::SensorModel &sensor);

    std::shared_ptr<drishti::sensor::SensorModel> & getSensor() { return m_sensor; }
    std::shared_ptr<spdlog::logger> & getLogger() { return m_logger; }
    std::shared_ptr<ThreadPool<128>> & getThreads() { return m_threads; }

protected:
    std::shared_ptr<drishti::sensor::SensorModel> m_sensor;
    std::shared_ptr<spdlog::logger> m_logger;
    std::shared_ptr<ThreadPool<128>> m_threads; 
};

_DRISHTI_SDK_END

#endif // DRISHTI_DRISHTI_MANAGER_IMPL_H 