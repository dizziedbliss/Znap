# TerminalAurapp

TerminalAurapp is a fun, interactive terminal assistant designed to make your terminal experience more exciting! It can fetch weather, play music, display system stats, tell jokes, and much more. With playful messages and cute features (including cowsay), this assistant aims to make your terminal a little more enjoyable.

## Features

- Greet you with fun messages ("hello", "hi")
- Fetch the weather of a predefined city (e.g., London)
- Play music from your local files
- Display your system's disk usage
- Show real-time system stats (CPU and memory usage)
- Tell you random jokes
- Show the current time
- Display the current month's calendar
- Fetch the latest news from an RSS feed

## Installation

To get started with TerminalAurapp, follow these steps:

1. **Clone the repository**: Clone this repository to your local machine using Git:

    ```bash
    git clone https://github.com/your-username/TerminalAurapp.git
    ```

2. **Navigate to the project directory**:

    ```bash
    cd TerminalAurapp
    ```

3. **Make the script executable (Optional)**:

    If you'd like to make the script executable, run:

    ```bash
    chmod +x terminal_aurapp.sh
    ```

4. **Install Dependencies**:

    Ensure you have all required dependencies installed:

    - `cowsay` (for the fun text-based cows)
    - `curl` (to fetch weather data)
    - `xmlstarlet` (to parse RSS feeds)
    - `mplayer` (to play music)
    - `jq` (for JSON parsing if using weather API)

    You can install these with the following command (for Ubuntu):

    ```bash
    sudo apt-get install cowsay curl xmlstarlet mplayer jq
    ```

5. **Run the Assistant**:

    To start the assistant, run:

    ```bash
    ./terminal_aurapp.sh
    ```

    Alternatively, if you've made the script executable:

    ```bash
    ./terminal_aurapp.sh
    ```

## Usage

Once the assistant is running, you can type various commands, and the assistant will respond accordingly. Here are some sample commands you can use:

- `"hello"` or `"hi"`: Greet the assistant.
- `"weather"`: Fetch the weather for your pre-configured city (e.g., London).
- `"play music"`: Play a predefined song.
- `"disk usage"`: Show your system's disk usage.
- `"sys stats"`: Show system stats like CPU and memory usage.
- `"joke"`: Get a random joke.
- `"time"` or `"current time"`: Check the current time.
- `"calendar"`: Display the current month's calendar.
- `"news"`: Fetch the latest news articles from the RSS feed.

To exit, just type `"exit"`.

### Example Output

```plaintext
Your command, Master: weather
Fetching weather details...
The current weather in London is: 15°C, clear sky 🌤️

Your command, Master: joke
 _______________________
< Why don’t skeletons fight each other? They don’t have the guts! >
 -----------------------
        \   ^__^
         \  (oo)\_______
            (__)\       )\/\
                ||----w |
                ||     ||
```

## How to Upgrade

- **Dynamic City Selection**: Upgrade the weather feature to allow users to specify the city for which they want to fetch the weather.
- **Voice Commands**: Integrate speech recognition to make the assistant respond to voice commands.
- **Music Library**: Allow users to select songs from their music library instead of a predefined track.
- **News Sources**: Integrate more RSS feeds or provide options for users to choose from different categories (e.g., tech, sports, etc.).
- **Persistent Data**: Implement a way to store user preferences, such as the preferred city for weather, or favorite music, across sessions.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

Feel free to clone, contribute, or modify the project to make it even more powerful. Enjoy your interactive assistant, and don't forget to keep it fun and playful! 🐄🎶🌤️