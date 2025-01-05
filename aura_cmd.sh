#!/bin/zsh

# Source the functions
source /home/dizziedbliss/CODE/aura/aura_fns

# Function to listen for user input and act like an AI
listen_for_commands() {
    while true; do
        echo -n "Your command, Master: "  # Prompt user for input
        read -r input                    # Capture user input
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
                echo "Goodbye, Master!" && break ;;
            *)
                echo "Sorry, I didn't understand: $input" ;;
        esac
    done
}

# Start the listener
listen_for_commands
