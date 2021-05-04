#ifndef PUZZLE_H
#define PUZZLE_H

#include <QVector>

class Puzzle
{
private:
    int size;
    QString theme;
    QVector<int> solution;
    QVector<QString> rows;
    QVector<QString> columns;
    QVector<int> userSolution;

public:
    Puzzle();
    Puzzle(int size);
    ~Puzzle();

    void addSolution(QVector<int> &solution);
    QVector<int> getSolution();
    void addRowDescription(QVector<QString> &rows);
    QVector<QString> getRowDescription();
    void addColumnDescription( QVector<QString> &columns);
    QVector<QString> getColumnDescription();
    void setTheme(QString theme);
    QString getTheme();

    int checkWithSolution(QVector<int> &userSolution);
    int checkSolution();
    QVector<int> getUserSolution() const;
    void setUserSolution(const QVector<int> &value);

    bool operator==(const Puzzle &puzzle);
    bool operator!=(const Puzzle &puzzle);
    int getSize() const;
    void setSize(int value);
};

#endif // PUZZLE_H
