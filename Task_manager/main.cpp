#include <iostream>
#include <vector>
#include <string>

class Task {
public:
    Task(const std::string& desc) : description(desc), completed(false) {}

    void markCompleted() {
        completed = true;
    }

    const std::string& getDescription() const {
        return description;
    }

    bool isCompleted() const {
        return completed;
    }

private:
    std::string description;
    bool completed;
};

class TaskList {
public:
    void printTasks() const {
        std::cout << "To-do list:\n";
        for (size_t i = 0; i < tasks.size(); ++i) {
            std::cout <<  i + 1 << ". ";
            if (tasks[i].isCompleted()) {
                std::cout << "[x] ";
            }
            else {
                std::cout << "[ ] ";
            }
            std::cout << tasks[i].getDescription() << "\n";
        }
    }

    void addTask(const std::string& desc) {
        tasks.emplace_back(desc);
    }

    void markTaskCompleted(size_t index) {
        if (index >= 1 && index <= tasks.size()) {
            tasks[index - 1].markCompleted();
        }
    }

private:
    std::vector<Task> tasks;
};

int main() {
    TaskList taskList;
    char choice{ 0 };

    do {
        system("cls");
        taskList.printTasks();

        std::cout << "\n";
        std::cout << "What do you want to do?\n";
        std::cout << "1. Add new task\n";
        std::cout << "2. Mark as complete\n";
        std::cout << "q. Quit program\n";
        std::cin >> choice;

        if (choice == '1') {
            system("cls");
            std::string newTaskDesc;
            std::cout << "Write description\n";
            std::cin.ignore(); 
            std::getline(std::cin, newTaskDesc);
            taskList.addTask(newTaskDesc);
        }
        else if (choice == '2') {
            system("cls");
            int index;
            std::cout << "Which task has been completed?: \n";
            taskList.printTasks();
            std::cin >> index;
            taskList.markTaskCompleted(index);
        }

    } while (choice != 'q');
    system("cls");
    std::cout << "See you soon!\n";

    return 0;
}
