#include "Group.h"
#include "../model/ProcessModule.h"
#include <log4cplus/loggingmacros.h>
#include <scxml/TriggerEvent.h>

namespace chilli {
namespace Group {

	Group::Group(model::ProcessModule * model, const std::string &ext, const std::string &smFileName)
		:Device(model, ext, smFileName)
	{
		std::string logName = "GroupImp";
		log = log4cplus::Logger::getInstance(logName);
		log.setAppendName("." + this->getId());
		LOG4CPLUS_DEBUG(log, " new a group object.");
	}

	Group::~Group() {
		LOG4CPLUS_DEBUG(log, " destruction a group object.");
	}

	void Group::processSend(Json::Value & jsonData, const void * param, bool & bHandled)
	{
		return Device::processSend(jsonData, param, bHandled);	
	}

	void Group::fireSend(const std::string &strContent, const void * param)
	{
		LOG4CPLUS_TRACE(log, " fireSend:" << strContent);
		Json::Value jsonData;
		Json::Reader jsonReader;

		if (!jsonReader.parse(strContent, jsonData)) {
			LOG4CPLUS_ERROR(log, strContent << " not json data.");
			return;
		}

		bool bHandled = false;
		this->processSend(jsonData, param, bHandled);
	}

}
}