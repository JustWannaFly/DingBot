#include <dpp/dpp.h>
#include <iostream>
#include "Commands.cpp"

int main(int argc, char *argv[])
{
    char* token = argv[1];
    shared_ptr<dpp::cluster> bot(new dpp::cluster(token));
    Commands commands(bot);

    bot->on_ready([&bot](const dpp::ready_t& event) {
        std::cout << "Logged in as " << bot->me.username << "!\n";
    });
    bot->on_message_create([&bot, &commands](const dpp::message_create_t& event) {
        if (event.msg->content.starts_with('!')) {
            commands.parseCommand(event);
        }
    });
    bot->start(false);
    return 0;
}