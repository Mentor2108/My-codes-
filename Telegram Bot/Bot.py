import telebot
import pandas as pd

BOT_TOKEN = "5826858416:AAF8AJ9D0GqohvYFcGgutFeLsNFnOAHDgK4"

# bot = telebot.TeleBot(BOT_TOKEN)

# @bot.message_handler(commands = ["start"])
# def startConv(message):
#     bot.reply_to(message, "Helloooo, I am here to help you with all your needs. Tell me what do you need help with. :)")

# @bot.message_handler(commands = ["stock"])
# def showStock(message):
#     stock_data = pd.read_csv("./Stock.csv")
#     # print(stock_data[""])
#     bot.send_message(message.chat.id, stock_data.head)
# bot.infinity_polling()

stock_data = pd.read_table()
print(stock_data)