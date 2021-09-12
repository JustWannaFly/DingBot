#include <dpp/dpp.h>
#include <commands/ACommand.h>
#include "commands/help.h"

using namespace std;

class Commands {

	shared_ptr<dpp::cluster> bot;
	const dpp::message_create_t* event;

	typedef void (Commands::*MemberFunc)(list<string>);
	unordered_map <string, MemberFunc> commands;
	unordered_map<string, unique_ptr<ACommand>> objCommands;


	void ding(list<string> args) {
		cout << "inside ding" << endl;
		bot->message_create(dpp::message(event->msg->channel_id, "dong!"));
	}
	void help(list<string> args) {
		cout << "inside help" << endl;
		bot->message_create(dpp::message(event->msg->channel_id, "I'm helping...\nSort of"));
	}
	void poll(list<string> args) {
		cout << "inside poll" << endl;
		bot->message_create(dpp::message(event->msg->channel_id, "Someday I'll be able to make a poll..."));
	}
public:
	Commands(shared_ptr<dpp::cluster> botParam) {
		bot = botParam;
		objCommands.insert(make_pair(Help::getInvokeText(), unique_ptr<ACommand> (new Help(bot))));

		//commands.insert(make_pair("help", &Commands::help));
		commands.insert(make_pair("ding", &Commands::ding));
		commands.insert(make_pair("poll", &Commands::poll));
	}
	void parseCommand(const dpp::message_create_t& eventRef) {
		
		event = &eventRef;
		string command = event->msg->content;
		
		size_t pos = 0;
		string piece;

		string func;
		list<string> args;
		command += " "; // Add a space to the end to grab the last piece
		while ((pos = command.find(" ")) != string::npos) {
			piece = command.substr(0, pos);
			command.erase(0, pos + 1);
			if (piece != "") {
				if (func == "") {
					piece.erase(0, 1);
					func = piece;
				}
				else {
					args.push_back(piece);
				}
			}
		}
		MemberFunc funcPtr = commands[func];
		if (funcPtr != nullptr) {
			return (this->*funcPtr)(args);
		} else if (objCommands[func] != nullptr) {
			objCommands[func]->execute(event, args);
			return;
		}
		cout << "Unable to find matching function for command:: " + func << endl;
	}
};
