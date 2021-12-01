#include <dpp/dpp.h>
#include <commands/ACommand.h>
#include "commands/Help.h"
#include "commands/Ding.h"
#include "commands/Poll.h"
#include "commands/Advent.h"
#include <vector>

using namespace std;

class Commands {

	shared_ptr<dpp::cluster> bot;
	const dpp::message_create_t* event;

	unordered_map<string, unique_ptr<ACommand>> objCommands;


public:
	Commands(shared_ptr<dpp::cluster> botParam) {
		bot = botParam;
		objCommands.insert(make_pair(Help::getInvokeText(), unique_ptr<ACommand> (new Help(bot))));
		objCommands.insert(make_pair(Ding::getInvokeText(), unique_ptr<ACommand> (new Ding(bot))));
		objCommands.insert(make_pair(Poll::getInvokeText(), unique_ptr<ACommand>(new Poll(bot))));
		objCommands.insert(make_pair(Advent::getInvokeText(), unique_ptr<ACommand>(new Advent(bot))));
	}
	void parseCommand(const dpp::message_create_t& eventRef) {
		
		event = &eventRef;
		string command = event->msg->content;
		
		size_t pos = 0;
		string piece;

		string func;
		vector<string> args;
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
		if (objCommands[func] != nullptr) {
			objCommands[func]->execute(event, args);
			return;
		}
		cout << "Unable to find matching function for command:: " + func << endl;
	}
};
