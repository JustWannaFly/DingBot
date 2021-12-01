#include "commands/Advent.h"
#include "advent/days/ADay.h"
#include "advent/days/Day01.h"

Advent::Advent(shared_ptr<dpp::cluster> bot) : ACommand(bot) {
	this->bot = bot;
	days.insert(make_pair("1", unique_ptr<ADay>(new Day01())));
}

string Advent::getInvokeText()
{
	return "aoc";
}

string Advent::getHelpText() {
	return "Calculates a specific advent of code challenge. Command is '!aoc 1 1' for day 1 part 1";
}

bool Advent::execute(const dpp::message_create_t* event, vector<string> args) {

	if (args.size() < 2) {
		bot->message_create(dpp::message(event->msg->channel_id, "Need to specify a day and part (!aoc 1 1)"));
		return false;
	}
	string day = args[0];
	string part = args[1];
	bot->message_create(dpp::message(event->msg->channel_id, "Calculating Day: " + day + " Part: " + part));
	string output;
	if (days[day] != nullptr) {
		output = days[day]->calculate(part);

	}
	string resultMessage = "Result for Day: " + day + " Part: " + part + "::\n" + output;
	bot->message_create(dpp::message(event->msg->channel_id, resultMessage));
	return true;
};

