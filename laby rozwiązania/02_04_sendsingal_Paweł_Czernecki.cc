#include <iostream>
#include <csignal>
#include <cstdlib>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <PID> <signal>\n";
        return 1;
    }

    int pid = std::atoi(argv[1]);
    int signalNumber = std::atoi(argv[2]);

    if (kill(pid, signalNumber) == 0) {
        std::cout << "Signal " << signalNumber << " sent to process with PID " << pid << std::endl;
    } else {
        std::cerr << "Failed to send signal.\n";
        return 1;
    }

    return 0;
}