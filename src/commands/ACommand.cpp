#include "commands/ACommand.h"

ACommand::ACommand(shared_ptr<dpp::cluster> bot) {
	this->bot = bot;
}
