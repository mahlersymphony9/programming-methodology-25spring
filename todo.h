#pragma once

class TodoList {
public:
    void init();
    void destroy();
    void add_task(const char* task);
    void remove_task(int index);
    const char** get_pending_tasks(int& count) const;

private:
    static const int MAX_TASKS = 32;
    char* tasks[MAX_TASKS];
    int task_count = 0;
};
