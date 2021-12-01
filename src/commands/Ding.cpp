#include "commands/Ding.h"

using namespace std;

Ding::Ding(shared_ptr<dpp::cluster> bot) : ACommand(bot) {
	this->bot = bot;
}

string Ding::getInvokeText() { 
	return "ding";
};

string Ding::getHelpText() {
	return "Responds to a \"!ding\" with a \"dong!\"";
}

bool Ding::execute(const dpp::message_create_t* event, vector<string> args) {
	bot->message_create(dpp::message(event->msg->channel_id, "dong!"));
	return true;
};
