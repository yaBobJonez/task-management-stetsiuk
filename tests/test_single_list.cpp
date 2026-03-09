#include <gtest/gtest.h>
#include <QStringListModel>

TEST(SingleList, AddItem) {
    QStringListModel model;
    QStringList list = model.stringList();

    list.append("Купити молоко");
    model.setStringList(list);

    EXPECT_TRUE(model.stringList().contains("Купити молоко"));
}

TEST(SingleList, RemoveItem) {
    QStringListModel model;
    QStringList list = { "Зробити лабу", "Написати тести" };

    model.setStringList(list);
    list.removeOne("Написати тести");
    model.setStringList(list);

    EXPECT_FALSE(model.stringList().contains("Написати тести"));
}

TEST(SingleList, EditItem) {
    QStringListModel model;
    QStringList list = { "Зробити лабу", "Написати тести", "Купити молоко" };

    model.setStringList(list);
    list.replace(0, "Вигуляти кота");
    model.setStringList(list);

    EXPECT_EQ(model.stringList().at(0), "Вигуляти кота");
}