#!/bin/bash

# Source the functions file to make the commands available
source /home/dizziedbliss/CODE/aura/aura_fns

# Function to listen for user input (jarvis commands)
listen_for_commands() {
    while true; do
        # Wait for user input and check for specific commands
        read -r input
        case "$input" in
            "hello" | "hi")
                greet ;;
            "weather")
                get_weather ;;
            "play music" | "music")
                play_music ;;
            "disk usage" | "usage")
                disk_usage ;;
            "sys stats" | "system stats")
                sys_stats ;;
            "joke" | "tell me a joke")
                tell_joke ;;
            "time" | "current time")
                get_time ;;
            "calendar")
                show_calendar ;;
            "news")
                get_news ;;
            "exit")
                echo "Goodbye, Master!" && exit ;;
            *)
                # If it's not a Jarvis command, just let it be executed as normal shell command
                eval "$input"
                ;;
        esac
    done
}

# Start the listener in the foreground
listen_for_commands
