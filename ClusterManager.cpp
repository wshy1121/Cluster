#include "ClusterManager.h"

static boost::mutex g_insMutex;

CClusterManager* CClusterManager::_instance = NULL;

CClusterManager* CClusterManager::instance() 
{
	if (NULL == _instance)
	{
		boost::unique_lock<boost::mutex> lock(g_insMutex);
		if (NULL == _instance)
		{
			_instance = new CClusterManager;
		}
	}
	return _instance;
}


CClusterManager::CClusterManager()
{
}

CClusterManager::~CClusterManager()
{
}


