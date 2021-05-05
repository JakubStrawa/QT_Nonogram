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

    int getSize() const;
    void setSize(int value);
    void setTheme(QString theme);
    QString getTheme();
    void addSolution(QVector<int> &solution);
    QVector<int> getSolution();
    void addRowDescription(QVector<QString> &rows);
    QVector<QString> getRowDescription();
    void addColumnDescription( QVector<QString> &columns);
    QVector<QString> getColumnDescription();
    QVector<int> getUserSolution() const;
    void setUserSolution(const QVector<int> &value);

    int checkWithSolution(QVector<int> &userSolution);
    int checkSolution();

    bool operator==(const Puzzle &puzzle);
    bool operator!=(const Puzzle &puzzle);
};

#endif // PUZZLE_H
