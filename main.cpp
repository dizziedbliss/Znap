#include <iostream>
#include <ncurses.h>
#include <ctime>
#include <cstdlib>
#include <string>
#include <unistd.h>
#include <vector>
#include <thread>

// Function to get current time
std::string getTime() {
    time_t t = time(0);
    struct tm* now = localtime(&t);
    char buffer[80];
    strftime(buffer, 80, "%H:%M:%S", now);
    return std::string(buffer);
}

// Function to get system stats (CPU, Memory, Disk)
std::string getCPUUsage() {
    FILE* file = popen("cat /proc/stat | grep '^cpu '", "r");
    if (!file) return "N/A";
    char buffer[128];
    fgets(buffer, sizeof(buffer), file);
    fclose(file);
    std::string line(buffer);
    return line.substr(5, 20);  // Extracts the usage info
}

std::string getRAMUsage() {
    FILE* file = popen("free -h | grep Mem", "r");
    if (!file) return "N/A";
    char buffer[128];
    fgets(buffer, sizeof(buffer), file);
    fclose(file);
    std::string line(buffer);
    return line.substr(9, 12);  // Extracts RAM usage info
}

std::string getDiskUsage() {
    FILE* file = popen("df -h | grep '^/dev/'", "r");
    if (!file) return "N/A";
    char buffer[128];
    fgets(buffer, sizeof(buffer), file);
    fclose(file);
    std::string line(buffer);
    return line.substr(11, 12);  // Extracts disk usage info
}

// Function for Matrix effect animation (Unimatrix-style)
void matrixAnimation(WINDOW* win) {
    srand(time(NULL));
    while (true) {
        for (int y = 1; y < 20; y++) {
            mvwprintw(win, y, rand() % 50 + 1, "%c", rand() % 26 + 65);  // Random letters A-Z
            wrefresh(win);
        }
        usleep(50000);  // Control animation speed
        werase(win);  // Clear matrix screen after printing
    }
}

// Function to display the system stats on the left panel
void displayStats(WINDOW* win) {
    while (true) {
        std::string time_str = getTime();
        std::string cpu_str = getCPUUsage();
        std::string ram_str = getRAMUsage();
        std::string disk_str = getDiskUsage();

        wclear(win);
        mvwprintw(win, 1, 1, "Time: %s", time_str.c_str());
        mvwprintw(win, 3, 1, "CPU Usage: %s", cpu_str.c_str());
        mvwprintw(win, 5, 1, "RAM Usage: %s", ram_str.c_str());
        mvwprintw(win, 7, 1, "Disk Usage: %s", disk_str.c_str());
        wrefresh(win);

        usleep(1000000);  // Refresh every second
    }
}

// Function to initialize terminal (Middle panel)
void runTerminal() {
    system("clear");  // Clear the terminal for neatness
    std::string command;
    while (true) {
        std::cout << "Your Zsh Terminal>> ";
        std::getline(std::cin, command);  // Take input
        system(command.c_str());  // Run the command
    }
}

int main() {
    // Initialize ncurses
    initscr();
    noecho();
    cbreak();
    curs_set(0);
    int height = 30, width = 80;

    // Create windows for left (stats), right (Matrix effect), and terminal
    WINDOW* left_win = newwin(height, 25, 0, 0);  // Left panel
    WINDOW* right_win = newwin(height, 25, 0, 25);  // Right panel for Matrix effect
    WINDOW* terminal_win = newwin(height, 50, 0, 50);  // Terminal window (middle panel)

    // Start system stats and Matrix animation in separate threads
    std::thread statsThread(displayStats, left_win);
    std::thread matrixThread(matrixAnimation, right_win);

    // Run terminal in the main thread
    runTerminal();

    // Join threads and clean up
    statsThread.join();
    matrixThread.join();

    // End ncurses mode
    endwin();
    return 0;
}
