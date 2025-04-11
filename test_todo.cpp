#include <gtest/gtest.h>
#include "todo.h"

TEST(TodoListTest, AddAndGetTasks) {
    TodoList list;
    list.init();
    list.add_task("Task1");
    list.add_task("Task2");

    int count;
    const char** tasks = list.get_pending_tasks(count);

    EXPECT_EQ(count, 2);
    EXPECT_STREQ(tasks[0], "Task1");
    EXPECT_STREQ(tasks[1], "Task2");

    list.destroy();
}

TEST(TodoListTest, RemoveTask) {
    TodoList list;
    list.init();
    list.add_task("A");
    list.add_task("B");
    list.remove_task(0);

    int count;
    const char** tasks = list.get_pending_tasks(count);
    EXPECT_EQ(count, 1);
    EXPECT_STREQ(tasks[0], "B");

    list.destroy();
}

TEST(TodoListTest, RemoveInvalidIndexThrows) {
    TodoList list;
    list.init();
    EXPECT_THROW(list.remove_task(0), std::out_of_range);
    list.destroy();
}

TEST(TodoListTest, AddTooManyTasksThrows) {
    TodoList list;
    list.init();
    for (int i = 0; i < 32; ++i) {
        list.add_task("x");
    }
    EXPECT_THROW(list.add_task("overflow"), std::overflow_error);
    list.destroy();
}
