#pragma once

#include "ACommand.h"

class Help : public ACommand {
private:
	shared_ptr<dpp::cluster> bot;
	shared_ptr<unordered_map<string, unique_ptr<ACommand>>> objCommands;
public:
	Help(shared_ptr<dpp::cluster> bot, shared_ptr<unordered_map<string, unique_ptr<ACommand>>> commands);
	static string getInvokeText();
	string ACommand::getHelpText();
	bool ACommand::execute(const dpp::message_create_t* event, vector<string> args);
};
