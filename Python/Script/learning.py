import pyautogui as auto
import time
import random

# Wait for 5 seconds to switch to the game window
time.sleep(2)

time_remaining_run = 0  # Time remaining in seconds for run/pup/piku commands
time_remaining_pray = 0  # Time remaining in seconds for pray commands

gem_count = 55  # Number of gems uses remaining
total_gems_remaining = 5  # Total number of gems available

num_run_pup_piku_command = 0  # Number of run/pup/piku commands to execute

# List of commands to be executed
commands = [
    'owo',
    'wh',
    'wb',
    'owo buy 1',
]

commands_run = [
    'owo run',
    'owo pup',
    'owo piku',
]

sentences = [
    "i am a random english sentence",
    "this is another random sentence",
    "hello, how are you?",
    "i love programming in golang",
    "i am not sure why life is so hard",
    "i am a boy who is very lonely",
    "why is the chat dead?",
    "dead",
    "no one is alive",
    "anyone here?",
    "yoooooooooooooooo",
    "talk please",
    "boredddd",
    "bro, tell me something",
    "whats up with u",
    "anything new with you?",
    "naa man",
    "i was watching anime",
    "have you seen daeath note?",
    "whjat about stein's gate",
    "okabe rintaro"
]

def sleep_and_reduce_time_remaining(min_time, max_time):
    """Sleep for a given number of seconds and reduce the time remaining for run/pup/piku and pray commands."""
    time_waited = random.uniform(min_time, max_time)  # Random wait time
    time.sleep(time_waited)  # Wait for a random time

    # Update the global time remaining variables
    global time_remaining_pray, time_remaining_run
    time_remaining_pray -= time_waited  # Decrease time remaining for pray commands
    time_remaining_run -= time_waited  # Decrease time remaining for run/pup/piku commands

# Function to execute a command
def execute_command(command):
    auto.typewrite(command)
    auto.press('enter')
    sleep_and_reduce_time_remaining(0.1, 1.5)  # Random delay between commands

def send_random_message():
    """Send a random message from a dictionary"""
    sentence = random.choice(sentences)
    auto.typewrite(sentence)
    auto.press('enter')

# Main loop to execute commands
while True:
    for command in commands:
        execute_command(command)
    gem_count-=1  # Decrease gem count by 1
    print(f"Gem count: {gem_count}")  # Print current gem count

    sleep_and_reduce_time_remaining(3, 3.5)  # Random delay between next commands

    if num_run_pup_piku_command > 0 and time_remaining_run < 0:
        for command in commands_run:
            execute_command(command)
        num_run_pup_piku_command -= 1
        time_remaining_run = 62

    sleep_and_reduce_time_remaining(3, 3.5)  # Random delay between next commands


    # Check if time remaining for pray command is less than 0
    if time_remaining_pray < 0:
        execute_command('owo pray')
        time_remaining_pray = 60*5

    if gem_count == 0:  # If no gems left, break the loop
        if total_gems_remaining < 0:
            print("No gems left. Stopping the script.")
            break
        execute_command('owo use 54 68 75')
        gem_count = 75  # Reset gem count to 75
        total_gems_remaining -= 1
        print(f"Total gems remaining: {total_gems_remaining}")        

    time.sleep(random.uniform(8.5, 9.5))  # Random delay before repeating the loop
    send_random_message()  # Send a random message after each cycle