#ifndef __CLUSTER_MANAGER_H
#define __CLUSTER_MANAGER_H
#include <boost/thread/mutex.hpp>
#include <boost/thread/thread.hpp>
#include "trace_worker.h"

class CClusterManager
{
public:
    static CClusterManager* instance();
private:    
    CClusterManager();
    ~CClusterManager();
private:
    static  CClusterManager* _instance;
};

#endif

