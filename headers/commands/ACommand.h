#pragma once

#include <string>
#include <dpp/dpp.h>

using namespace std;

class ACommand
{
private:
	shared_ptr<dpp::cluster> bot;
public:
	ACommand(shared_ptr<dpp::cluster> bot);
	virtual string getHelpText() = 0;
	virtual bool execute(const dpp::message_create_t* event, vector<string> args) = 0;
};