#include "commands/ACommand.h"

ACommand::ACommand(shared_ptr<dpp::cluster> bot) {
	this->bot = bot;
}

string ACommand::getInvokeText() {
	return "This needs to be overridden";
}
