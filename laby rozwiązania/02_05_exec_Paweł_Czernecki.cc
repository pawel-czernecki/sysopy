#include <iostream>
#include <unistd.h>

int main() {
    std::cout << "Hello, I'm exec program!" << std::endl;
    getchar();

    execl("./another", "another", nullptr);

    // If execl fails, print an error message
    std::cerr << "Error in exec.\n";

    return 1;
}