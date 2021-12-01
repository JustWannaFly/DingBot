#include "commands/Help.h"

using namespace std;

Help::Help(shared_ptr<dpp::cluster> bot, shared_ptr<unordered_map<string, unique_ptr<ACommand>>> commands) : ACommand(bot) {
	this->bot = bot;
	this->objCommands = commands;
}

string Help::getInvokeText() { 
	return "help";
};

string Help::getHelpText() {
	return "The \"help\" command will display a list of commands supported by "
		"DingBot or will display details about how to use each command.\n\n"
		"To see the details about an command enter \"!help <command>\"";
}

bool Help::execute(const dpp::message_create_t* event, vector<string> args) {
	string messageContent;
	shared_ptr<vector<string>> foo;
	if (args.size() == 0) {
		vector<string> commands;
		for (auto iter = objCommands->begin(); iter != objCommands->end(); ++iter) {
			commands.push_back(iter->first);
		}
		messageContent = "Here's a list of all the supported commands";
		for (string command : commands) {
			messageContent = messageContent + "\n" + command;
		}
	}
	else {
		messageContent = objCommands->at(args[0])->getHelpText();
	}
	bot->message_create(dpp::message(event->msg->channel_id, messageContent));
	return true;
};
