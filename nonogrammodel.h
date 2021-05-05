#ifndef NONOGRAMMODEL_H
#define NONOGRAMMODEL_H

#include <QAbstractItemModel>
#include "puzzle.h"

class NonogramModel : public QAbstractItemModel
{
    Q_OBJECT
    Q_PROPERTY(QVector<Puzzle> puzzles READ puzzles WRITE setPuzzles NOTIFY puzzlesChanged)

public:
    explicit NonogramModel(QVector<Puzzle> puzzles, QObject *parent = nullptr);

    // Basic functionality:
    QModelIndex index(int row, int column,
                      const QModelIndex &parent = QModelIndex()) const override;
    QModelIndex parent(const QModelIndex &index) const override;

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // Editable:
    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

    QVector<Puzzle> puzzles() const;

    int getPuzzleRowNumber(QString theme, QString size);

public slots:
    void setPuzzles(QVector<Puzzle> puzzles);

signals:
    void puzzlesChanged(QVector<Puzzle> puzzles);

private:
    QVector<Puzzle> m_puzzles;
};

#endif // NONOGRAMMODEL_H
