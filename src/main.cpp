#include <dpp/dpp.h>
#include <fmt/core.h>
#include <cstdlib>

int main() {
    if (std::getenv("BOT_TOKEN") == nullptr) {
        fmt::println("Please provide bot token as a env variable: BOT_TOKEN");
        return 1;
    }

    std::string bot_token(std::getenv("BOT_TOKEN"));
	dpp::cluster bot(bot_token);

	bot.on_slashcommand([](auto event) {
		if (event.command.get_command_name() == "ping") {
			event.reply("Pong!");
		}
	});

	bot.on_ready([&bot](auto event) {
		if (dpp::run_once<struct register_bot_commands>()) {
			bot.global_command_create(
				dpp::slashcommand("ping", "Ping pong!", bot.me.id)
			);
		}
	});

	bot.start(dpp::st_wait);
	return 0;
}
