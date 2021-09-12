#include "commands/Help.h"

using namespace std;

Help::Help(shared_ptr<dpp::cluster> bot) : ACommand(bot) {
	this->bot = bot;
}

string Help::getInvokeText() { 
	return "help";
};

string Help::getHelpText() {
	return "The \"help\" command will display a list of commands supported by "
		"DingBot or will display details about how to use each command.\n\n"
		"To see the details about an command enter \"!help <command>\"";
}

bool Help::execute(const dpp::message_create_t* event, list<string> args) {
	string messageContent;
	if (args.size() == 0) {
		messageContent = "Someday I'll tell list all the commands that I support, but not quite yet...";
	}
	else {
		messageContent = "Someday I'll tell you details about the \"" + args.front() +"\" command";
	}
	bot->message_create(dpp::message(event->msg->channel_id, messageContent));
	return true;
};
