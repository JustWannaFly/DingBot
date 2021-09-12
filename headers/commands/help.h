#pragma once

#include "ACommand.h"

class Help : public ACommand {
private:
	shared_ptr<dpp::cluster> bot;
public:
	Help(shared_ptr<dpp::cluster> bot);
	static string getInvokeText();
	string ACommand::getHelpText();
	bool ACommand::execute(const dpp::message_create_t* event, list<string> args);
};
