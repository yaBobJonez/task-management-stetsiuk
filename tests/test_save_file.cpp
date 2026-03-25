#include <gtest/gtest.h>
#include <QStringListModel>
#include <QTextStream>
#include <QBuffer>

TEST(SaveFile, WriteToBuffer) {
    QStringListModel model1({ "Зробити лабу", "Написати тести" });
    QStringListModel model2({ "Купити молоко" });

    QBuffer buffer;
    buffer.open(QIODevice::ReadWrite);
    QTextStream os(&buffer);

    os << model1.stringList().join(",") << "\n";
    os << model2.stringList().join(",") << "\n";
    os.flush();

    buffer.seek(0);
    QString expected = "Зробити лабу,Написати тести\nКупити молоко\n";
    EXPECT_EQ(buffer.readAll(), expected.toUtf8());
}

TEST(SaveFile, ReadFromBuffer) {
    QByteArray inputData = "Зробити лабу,Написати тести\nКупити молоко\n";

    QBuffer buffer(&inputData);
    buffer.open(QIODevice::ReadOnly);
    QTextStream is(&buffer);

    QStringListModel parsedModel1(is.readLine().split(",", Qt::SkipEmptyParts));
    QStringListModel parsedModel2(is.readLine().split(",", Qt::SkipEmptyParts));

    QStringList expectedList1 = { "Зробити лабу", "Написати тести" };
    QStringList expectedList2 = { "Купити молоко" };
    EXPECT_EQ(parsedModel1.stringList(), expectedList1);
    EXPECT_EQ(parsedModel2.stringList(), expectedList2);
}