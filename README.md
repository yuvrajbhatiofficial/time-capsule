# Time-Capsule

## A C++ Console Application for Scheduled Message Delivery

Time-Capsule is a simple, yet engaging, C++ console application designed to let users create and store messages that are "delivered" at a specified future date and time. It's like sending a letter to your future self, allowing for self-reflection, reminders, or just a fun way to revisit past thoughts.

## Features

*   **Create Time Capsules:** Easily compose messages to be delivered at a precise future moment.
*   **Scheduled Delivery:** Define the exact year, month, day, hour, and minute for your message to be revealed.
*   **Message Retrieval:** A dedicated option to check for and display all messages that have reached their scheduled delivery time.
*   **Persistent Storage:** All time capsules are securely saved to a local text file (`time_capsule_data.txt`), ensuring your messages persist across program runs.
*   **User-Friendly Interface:** A clear, console-based menu guides users through creating and checking their time capsules.

## Installation

To get the Time-Capsule application up and running on your local machine, follow these steps:

### Prerequisites

*   A C++ compiler (e.g., g++, Clang)
*   Git (for cloning the repository)

### Steps

1.  **Clone the Repository:**
    ```bash
    git clone https://github.com/your-username/time-capsule.git
    cd time-capsule/C++
    ```
2.  **Compile the Application:**
    Use your C++ compiler to compile the `main.c++` file.
    ```bash
    g++ main.c++ -o main
    ```
3.  **Run the Application:**
    Execute the compiled binary.
    ```bash
    ./main
    ```

## Usage

Upon running the application, you will be presented with a main menu:

```
*----*----*----* WELCOME TO TIME CAPSULE PROGRAM *----*----*----* 
*-----------------------------------*
|               MENU                |
|-----------------------------------|
|1: create a capsule (push message) |
|-----------------------------------|
|2: check for message               |
|-----------------------------------|
|3: Exit                            |
|___________________________________|
```

1.  **Create a capsule (push message):**
    *   Enter `1` and press Enter.
    *   You will be prompted to enter your message, followed by the desired delivery year, month (1-12), day (1-31), hour (0-23), and minute (0-59). The application includes basic input validation for date and time components.

2.  **Check for message:**
    *   Enter `2` and press Enter.
    *   The application will scan `time_capsule_data.txt` and display any messages that have reached or passed their scheduled delivery time. Messages scheduled for a later time will be noted.

3.  **Exit:**
    *   Enter `3` and press Enter to exit the program.

## Tech Stack

*   **C++**: The core programming language used for the application logic.
*   **Standard Libraries**:
    *   `iostream`: For input and output operations (console interaction).
    *   `string`: For handling dynamic text messages.
    *   `fstream`: For file input/output operations (persisting time capsule data).
    *   `ctime`: For retrieving and manipulating current date and time.
    *   `chrono`: Included, indicating potential for more advanced time functionalities.

## Contribution

Contributions are welcome! If you have suggestions for improvements, bug fixes, or new features, please follow these guidelines:

1.  **Fork the repository.**
2.  **Create a new branch** for your feature or bug fix: `git checkout -b feature/your-feature-name` or `bugfix/issue-description`.
3.  **Commit your changes** with a clear and descriptive message.
4.  **Push your branch** to your forked repository.
5.  **Open a Pull Request** to the `main` branch of this repository.

Please use the provided [Bug Report](.github/ISSUE_TEMPLATE/bug_report.md) and [Feature Request](.github/ISSUE_TEMPLATE/feature_request.md) templates when applicable.

## License

This project is open-source and available under the MIT License. See the `LICENSE` file (to be added) for more details.

---

###
