#include "todo.h"
#include <cstring>
#include <stdexcept>

void TodoList::init() {
    task_count = 0;
}

void TodoList::destroy() {
    for (int i = 0; i < task_count; ++i) {
        delete[] tasks[i];
    }
    task_count = 0;
}

void TodoList::add_task(const char* task) {
    if (task_count >= MAX_TASKS)
        throw std::overflow_error("Too many tasks");

    tasks[task_count] = new char[strlen(task) + 1];
    strcpy(tasks[task_count], task);
    ++task_count;
}

void TodoList::remove_task(int index) {
    if (index < 0 || index >= task_count)
        throw std::out_of_range("Invalid index");

    delete[] tasks[index];
    for (int i = index; i < task_count - 1; ++i)
        tasks[i] = tasks[i + 1];
    --task_count;
}

const char** TodoList::get_pending_tasks(int& count) const {
    count = task_count;
    return const_cast<const char**>(tasks);
}
