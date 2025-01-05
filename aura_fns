#!/bin/zsh

function greet() {
    cowsay "Hello, Master! How can I assist you today?"
}

function get_weather() {
    echo "Fetching weather details..."
    
    api_key="d202c660f7c0452ea10105424241112"
    city="Hassan"
    
    # Fetch weather data from WeatherAPI
    weather_data=$(curl -s "http://api.weatherapi.com/v1/current.json?key=$api_key&q=$city")
    
    # Check if the data is valid
    if [[ -z "$weather_data" ]]; then
        echo "Sorry, I couldn't fetch the weather data."
        return
    fi
    
    # Extract relevant weather information
    temperature=$(echo "$weather_data" | grep -o '"temp_c":[^,]*' | cut -d: -f2)
    condition=$(echo "$weather_data" | grep -o '"text":".*"' | cut -d: -f2 | sed 's/"//g')
    
    # Display the weather info
    echo "Current weather in $city: $temperature°C, $condition"
}



function play_music() {
    echo "Let's play some music! 🎶"
    mplayer /home/dizziedbliss/Music/SHAED_-_Trampoline_Official_Video_320kbps.mp3
}

function disk_usage() {
    echo "Here's the disk usage status:"
    df -h
}

function sys_stats() {
    echo "Displaying system stats (CPU, memory):"
    top -n 1 | head -n 10
}

function tell_joke() {
    cowsay "Why don’t skeletons fight each other? They don’t have the guts!"
}

function get_time() {
    echo "The current time is:"
    date
}

function show_calendar() {
    cowsay "Here’s the calendar for this month:"
    ncal
}

function get_news() {
  echo "Fetching latest news..."
  
  # Fetch the RSS feed
  news_feed=$(curl -s "https://rss.app/feeds/pm0uqCDJDOSA7nlJ.xml")
  
  # Check if the fetched content is empty
  if [[ -z "$news_feed" ]]; then
    echo "Sorry, Master. The RSS feed is empty or unavailable. 😔"
    return
  fi
  
  # Extract the titles and links
  titles_and_links=$(echo "$news_feed" | xmlstarlet sel -t -m "//item" -v "concat(title, ' - ', link)" -n)
  
  # Check if we have any titles
  if [[ -z "$titles_and_links" ]]; then
    echo "Sorry, Master. No news found. 😔"
    return
  fi

  # Format the output
  echo -e "Latest News:\n"

  # Loop through each title and link
  while IFS= read -r line; do
    title=$(echo "$line" | cut -d '-' -f 1)
    link=$(echo "$line" | cut -d '-' -f 2-)
    
    # Print title only
    echo -e "📰 \033[1;34m$title\033[0m"
    
    # Add the "See More" as a clickable link
    echo -e "\033]8;;$link\033\\[See More]\033]8;;\033\\"
  done <<< "$titles_and_links"
}


echo "Functions sourced successfully!"
