#include "nonogrammodel.h"

NonogramModel::NonogramModel(QVector<Puzzle> puzzles, QObject *parent)
    : QAbstractItemModel(parent), m_puzzles(puzzles)
{
}

QModelIndex NonogramModel::index(int row, int column, const QModelIndex &parent) const
{
    if (parent.isValid()) return QModelIndex();
    if (row >= m_puzzles.count() || column >= 6 || column < 0 || row < 0)
        return QModelIndex();
    return createIndex(row, column, nullptr);
}

QModelIndex NonogramModel::parent(const QModelIndex &index) const
{
    return QModelIndex();
}

int NonogramModel::rowCount(const QModelIndex &parent) const
{
    return parent.isValid() ? 0 : m_puzzles.count();
}

int NonogramModel::columnCount(const QModelIndex &parent) const
{
    return parent.isValid() ? 0 : 6;
}

QVariant NonogramModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || m_puzzles.count() == 0)
        return QVariant();

    Puzzle tmp = m_puzzles[index.row()];
    switch(index.column())
    {
        case 0: return tmp.getTheme();
        case 1: return tmp.getSize();
        case 2: return QVariant::fromValue(tmp.getSolution());
        case 3: return tmp.getRowDescription();
        case 4: return tmp.getColumnDescription();
        case 5: return QVariant::fromValue(tmp.getUserSolution());
        default: return QVariant();
    }
}

bool NonogramModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(!index.isValid())
            return false;

    if (data(index, role) != value)
    {

        if (index.column() == 0)
        {
            this->m_puzzles[index.row()].setTheme(value.toString());
            emit dataChanged(index, index, QVector<int>() << role);
            return true;
        }
        else if(index.column() == 1)
        {
            this->m_puzzles[index.row()].setSize(value.toInt());
            emit dataChanged(index, index, QVector<int>() << role);
            return true;
        }
        else if(index.column() == 2)
        {
            QVector<int> vector = value.value<QVector<int>>();
            this->m_puzzles[index.row()].addSolution(vector);
            emit dataChanged(index, index, QVector<int>() << role);
            return true;
        }
        else if(index.column() == 3)
        {
            QList<QString> list = value.toStringList();
            this->m_puzzles[index.row()].addRowDescription(list);
            emit dataChanged(index, index, QVector<int>() << role);
            return true;
        }
        else if(index.column() == 4)
        {
            QList<QString> list = value.toStringList();
            this->m_puzzles[index.row()].addColumnDescription(list);
            emit dataChanged(index, index, QVector<int>() << role);
            return true;
        }
        else if(index.column() == 5)
        {
            QVector<int> vector = value.value<QVector<int>>();
            this->m_puzzles[index.row()].setUserSolution(vector);
            emit dataChanged(index, index, QVector<int>() << role);
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

Qt::ItemFlags NonogramModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsEditable;
}

void NonogramModel::setPuzzles(QVector<Puzzle> puzzles)
{
    if(puzzles.count() != m_puzzles.count())
    {
        // model size changed
        beginResetModel();
        m_puzzles = puzzles;
        endResetModel();
        emit puzzlesChanged(m_puzzles);
        return;
    }
    for(int i=0; i<m_puzzles.count(); i++)
    {
        if(m_puzzles[i] != puzzles[i])
        {
            // model content changed
            beginResetModel();
            m_puzzles = puzzles;
            endResetModel();
            emit puzzlesChanged(m_puzzles);
            return;
        }
    }
}

QVector<Puzzle> NonogramModel::puzzles() const
{
    return m_puzzles;
}
