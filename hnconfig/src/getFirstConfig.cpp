#include "hnconfig.h"

std::string HNConfig::getFirstConfig(std::string key, bool ex){
	auto configs = this->getConfig(key, ex);

	if (configs.empty())
		return "";

	return configs.at(0);
}
