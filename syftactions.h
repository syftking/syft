#ifndef SYFTACTIONS_H
#define SYFTACTIONS_H

#include <QString>

#include "syftaction.h"
#include "syftfile.h"
#include "syftorganizer.h"


// Create Subdirectory
class CreateSubdirectoryAction : public SyftAction {
public:
    CreateSubdirectoryAction(QString baseDirectory,
                             QString subDirectory);
    virtual int Perform();
    virtual int Revert();

private:
    QString m_baseDirectory;
    QString m_subDirectory;
};

// Move Sorter to another directory
class ChangeDirectoryAction : public SyftAction {
public:
    ChangeDirectoryAction(SyftOrganizer* organizer,
                          QString originalPath,
                          QString newPath);
    virtual int Perform();
    virtual int Revert();

private:
    SyftOrganizer* m_organizer;
    QString m_originalPath;
    QString m_newPath;
};

// Rename File
class RenameFileAction : public SyftAction {
public:
    RenameFileAction(SyftFile* file, QString newName);
    virtual int Perform();
    virtual int Revert();

private:
    SyftFile* m_file;
    QString m_originalName;
    QString m_newName;
};

// Rename Directory
class RenameDirectoryAction : public SyftAction {
public:
    RenameDirectoryAction(SyftDir* originalName, QString newName);
    virtual int Perform();
    virtual int Revert();

private:
    SyftDir* m_dir;
    QString m_originalName;
    QString m_newName;
};

// Move File
class MoveFileAction : public RenameFileAction {
public:
    MoveFileAction(SyftFile* file, QString newName, SyftOrganizer* organizer);
    virtual int Perform();
    virtual int Revert();
private:
    SyftOrganizer* m_organizer;
    SyftFile* m_file;
};

class DeleteFileAction : public SyftAction {
    QString m_fileName;
    QByteArray m_data;
public:
    DeleteFileAction(SyftFile* file);
    virtual int Perform();
    virtual int Revert();
};

#endif // SYFTACTIONS_H
