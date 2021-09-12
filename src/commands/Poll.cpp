#include "commands/Poll.h"

using namespace std;

Poll::Poll(shared_ptr<dpp::cluster> bot) : ACommand(bot) {
	this->bot = bot;
}

string Poll::getInvokeText() {
	return "poll";
};

string Poll::getHelpText() {
	return "Someday I'll let you make a poll";
}

bool Poll::execute(const dpp::message_create_t* event, list<string> args) {
	string messageContent = "I can't make a poll yet, but someday I'll be able to";
	
	bot->message_create(dpp::message(event->msg->channel_id, messageContent));
	return true;
};
