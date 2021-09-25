#ifndef SYFTACTIONMANAGER_H
#define SYFTACTIONMANAGER_H

#include <list>

#include <QObject>

#include "syftfile.h"
#include "syftaction.h"

class SyftActionManager : public QObject
{
    Q_OBJECT
public:
    SyftActionManager();

    void AddAction(SyftAction* action);
    void UndoAction();
    void RedoAction();
    void RepeatAction(SyftFile* file);

signals:
    void RefreshFileTitle();

private:
    std::list<SyftAction*> m_previousActions;
    std::list<SyftAction*> m_undoneActions;
};

#endif // SYFTACTIONMANAGER_H
