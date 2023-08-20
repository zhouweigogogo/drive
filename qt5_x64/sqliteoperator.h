#ifndef SQLITEOPERATOR_H
#define SQLITEOPERATOR_H
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QVector>
#include <QStringList>
typedef struct
{
    QString userId;
    QString userName;
    QString userPassword;
    QString userPermission;
    QString userConfigure;
}sqlData;



class SqliteOperator
{
public:
    SqliteOperator();

    // 打开数据库
    bool openDb(void);
    // 创建数据表
    void createTable(void);
    // 判断数据表是否存在
    bool isTableExist(QString& tableName);
    // 查询全部数据
    QVector<sqlData> queryTable();
    // 插入数据
    bool singleInsertData(sqlData &singleData); // 插入单条数据
    void moreInsertData(QList<sqlData> &moreData); // 插入多条数据
    QStringList queryData(QString userId);
    // 修改数据
    bool modifyData(QString userId, QString userName, QString userPassword, QString userPermission,QString userConfigure);
    // 删除数据
    bool deleteData(QString userId);
    //删除数据表
    void deleteTable(QString& tableName);
    // 关闭数据库
    void closeDb(void);

private:
    QSqlDatabase database;// 用于建立和数据库的连接
};
#endif // SQLITEOPERATOR_H
