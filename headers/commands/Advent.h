#pragma once

#include "ACommand.h"
#include "advent/days/ADay.h"

class Advent : public ACommand {
private:
	shared_ptr<dpp::cluster> bot;
	unordered_map<string, unique_ptr<ADay>> days;
public:
	Advent(shared_ptr<dpp::cluster> bot);
	static string getInvokeText();
	string ACommand::getHelpText();
	bool ACommand::execute(const dpp::message_create_t* event, vector<string> args);
};
