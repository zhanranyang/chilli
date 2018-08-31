#pragma once
#include <string>
#include <map>
#include <vector>
#include "Action.h"
#include "../SendInterface.h"

namespace fsm
{
namespace model
{
	/// </summary>
	class  Send :public Action
	{
	private:
		std::string id;
		std::string idexpr;
		std::string target;
		std::string targetexpr;
		std::string type;
		std::string typeexpr;
		std::string from;
		std::string fromexpr;
		std::string dest;
		std::string destexpr;
		std::string _event;
		//std::string namelist;
		std::string eventexpr;
		FireDataType fireData;

	public:
		Send(xmlNodePtr xNode,const std::string &session,const std::string &filename);
		const std::string& getId()const;
		void setId(const std::string &strValue);
		//std::string& getIdLocation();
		const std::string& getTarget()const;
		const std::string& getType()const;
		const std::string& getEvent()const;
		//std::string& getEventExpr();
		const std::string& getFrom()const;
		//std::string& getNamelist();
		//std::string& getTargetExpr();
		const std::string& getDestination()const;
		const FireDataType & getFireData()const;
		//std::map<std::string, std::string>& getParams();
		virtual  void execute(fsm::Context * ctx);
	};
}
}