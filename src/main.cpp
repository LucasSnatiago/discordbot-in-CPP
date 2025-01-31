#include <dpp/dpp.h>
#include <fmt/core.h>

#include <cstdlib>
#include <thread>

int main() {
  if (std::getenv("BOT_TOKEN") == nullptr) {
    fmt::println("Please provide bot token as a env variable: BOT_TOKEN");
    return 1;
  }

  std::string bot_token(std::getenv("BOT_TOKEN"));
  dpp::cluster bot(bot_token, dpp::i_all_intents);

  bot.on_log(dpp::utility::cout_logger());

  bot.on_slashcommand([&bot](const dpp::slashcommand_t& event) {
    if (event.command.get_command_name() == "ping") {
      event.reply("Pong!");

    }
	// else if (event.command.get_command_name() == "shutdown") {
    //   bot.shutdown();
    // }
  });

  bot.on_message_create([&bot](const dpp::message_create_t &event) {
	if (event.msg.author.id == bot.me.id)
		return;

	if (event.msg.content.find("teste") != std::string::npos) {
		event.reply("O teste está funcionanado corretamente!", false);
	}
  });

  /* The event is fired when someone issues your commands */
  bot.on_slashcommand([&bot](const dpp::slashcommand_t& event) {
    /* Check which command they ran */
    if (event.command.get_command_name() == "info") {
      /* Create an embed */
      dpp::embed embed =
          dpp::embed()
              .set_color(dpp::colors::sti_blue)
              .set_title("Discord Music Bot CPP")
              .set_url("https://github.com/LucasSnatiago/discordbot-in-CPP")
              .set_author(
                  "Lucas Santiago", "https://github.com/LucasSnatiago",
                  "https://avatars.githubusercontent.com/u/24521882?v=4")
              .set_description("A simple bot made to play music all in cpp.")
              .set_image("https://dpp.dev/DPP-Logo.png")
              .set_timestamp(time(0));

      /* Create a message with the content as our new embed. */
      dpp::message msg(event.command.channel_id, embed);

      /* Reply to the user with the message, containing our embed. */
      event.reply(msg);
    }
  });

  bot.on_ready([&bot](const dpp::ready_t& event) {
    if (dpp::run_once<struct register_bot_commands>()) {
      dpp::slashcommand ping("ping", "Ping pong!", bot.me.id);
      dpp::slashcommand play("play", "Play a song in your voice channel", bot.me.id);
      dpp::slashcommand shutdown("shutdown", "Shutdown bot!", bot.me.id);
      dpp::slashcommand info("info", "Show bot's information", bot.me.id);

      bot.global_bulk_command_create({ping, play, shutdown, info});
    }
  });

  // Start bot
  bot.start(dpp::st_wait);
  return 0;
}
