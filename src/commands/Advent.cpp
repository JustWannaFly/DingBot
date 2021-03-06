#include "commands/Advent.h"
#include "advent/days/ADay.h"
#include "advent/days/Day01.h"
#include "advent/days/Day02.h"
#include "advent/days/Day03.h"
#include "advent/days/Day04.h"
#include "advent/days/Day05.h"
#include "advent/days/Day06.h"
#include "advent/days/Day07.h"
#include "advent/days/Day08.h"
#include "advent/days/Day09.h"

Advent::Advent(shared_ptr<dpp::cluster> bot) : ACommand(bot) {
	this->bot = bot;
	days.insert(make_pair("1", unique_ptr<ADay>(new Day01())));
	days.insert(make_pair("2", unique_ptr<ADay>(new Day02())));
	days.insert(make_pair("3", unique_ptr<ADay>(new Day03())));
	days.insert(make_pair("4", unique_ptr<ADay>(new Day04())));
	days.insert(make_pair("5", unique_ptr<ADay>(new Day05())));
	days.insert(make_pair("6", unique_ptr<ADay>(new Day06())));
	days.insert(make_pair("7", unique_ptr<ADay>(new Day07())));
	days.insert(make_pair("8", unique_ptr<ADay>(new Day08())));
	days.insert(make_pair("9", unique_ptr<ADay>(new Day09())));
}

string Advent::getInvokeText()
{
	return "aoc";
}

string Advent::getHelpText() {
	return "Calculates a specific advent of code challenge. Command is '!aoc 1 1' for day 1 part 1\n"
		"For more information go to www.adventofcode.com";
}

bool Advent::execute(const dpp::message_create_t* event, vector<string> args) {

	if (args.size() < 2) {
		bot->message_create(dpp::message(event->msg->channel_id, "Need to specify a day and part (!aoc 1 1)"));
		return false;
	}
	string day = args[0];
	string part = args[1];
	string resultMessage;
	string output;
	if (days[day] != nullptr) {
		bot->message_create(dpp::message(event->msg->channel_id, "Calculating Advent of Code Day: " + day + " Part: " + part));
		output = days[day]->calculate(part);
		resultMessage = "==== Result for Day: " + day + " Part: " + part + " ====\n" + output;
	}
	else {
		resultMessage = "Sorry but I don't yet have the challenge for day " + day;
	}
	bot->message_create(dpp::message(event->msg->channel_id, resultMessage));
	return true;
};

