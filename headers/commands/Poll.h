#pragma once

#include "ACommand.h"

class Poll : public ACommand {
private:
	shared_ptr<dpp::cluster> bot;
public:
	Poll(shared_ptr<dpp::cluster> bot);
	static string getInvokeText();
	string ACommand::getHelpText();
	bool ACommand::execute(const dpp::message_create_t* event, vector<string> args);
};
