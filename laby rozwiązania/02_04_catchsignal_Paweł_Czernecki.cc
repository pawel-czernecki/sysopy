#include <iostream>
#include <csignal>
#include <cstring>

void signalHandler(int signum) {
    std::cout << "Signal received: " << strsignal(signum) << " (" << signum << ")\n";
}

int main() {
    // Set up signal handler
    signal(SIGINT, signalHandler);
    signal(SIGTERM, signalHandler);
    // Add more signals as needed

    std::cout << "Waiting for signals. Press Ctrl+C to exit.\n";

    // Infinite loop to keep the program running
    while (true) {
        // Do nothing, just wait for signals
    }

    return 0;
}