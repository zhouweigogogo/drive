#include "sqliteoperator.h"

// 构造函数中初始化数据库对象，并建立数据库
SqliteOperator::SqliteOperator()
{
    if (QSqlDatabase::contains("qt_sql_default_connection"))
    {
        database = QSqlDatabase::database("qt_sql_default_connection");
    }
    else
    {
        // 建立和SQlite数据库的连接
        database = QSqlDatabase::addDatabase("QSQLITE");
        // 设置数据库文件的名字
        database.setDatabaseName("MyDataBase.db");
    }
}

// 打开数据库
bool SqliteOperator::openDb()
{
    if (!database.open())
    {
        qDebug() << "Error: Failed to connect database." << database.lastError();
    }
    else
    {
        // do something
    }

    return true;
}

// 创建数据表
void SqliteOperator::createTable()
{
    // 用于执行sql语句的对象
    QSqlQuery sqlQuery;
    // 构建创建数据库的sql语句字符串
    QString createSql = QString("create table if not exists userInfo(userId nchar(50) not null primary key,\
                                userName nchar(50) not null,\
                                userPassword nchar(50) not null,\
                                userPermission nchar(50) not null,\
                                userConfigure nchar(100) not null);");
    sqlQuery.prepare(createSql);
    // 执行sql语句
    if(!sqlQuery.exec())
    {
        qDebug() << "Error: Fail to create table. " << sqlQuery.lastError();
    }
    else
    {
        qDebug() << "Table created!";
    }
    sqlQuery.clear();
    sqlQuery.finish();
}

// 判断数据库中某个数据表是否存在
bool SqliteOperator::isTableExist(QString& tableName)
{
    QSqlDatabase database = QSqlDatabase::database();
    if(database.tables().contains(tableName))
    {
        return true;
    }
    return false;
}

// 查询全部数据
QVector<sqlData> SqliteOperator::queryTable()
{
    QVector<sqlData> res;
    QSqlQuery sqlQuery;
    sqlQuery.exec("SELECT * FROM userInfo");
    if(!sqlQuery.exec())
    {
        qDebug() << "Error: Fail to query table. " << sqlQuery.lastError();
    }
    else
    {
        while(sqlQuery.next())
        {
            QString userId = sqlQuery.value(0).toString();
            QString userName = sqlQuery.value(1).toString();
            QString userPassword = sqlQuery.value(2).toString();
            QString userPermission = sqlQuery.value(3).toString();
            QString userConfigure = sqlQuery.value(4).toString();
//            qDebug()<<QString("userId:%1 userName:%2 userPassword:%3 userPermission:%4 userConfigure:%5")\
                      .arg(userId).arg(userName).arg(userPassword).arg(userPermission).arg(userConfigure);
            sqlData temp;
            temp.userId=userId;
            temp.userName=userName;
            temp.userPassword=userPassword;
            temp.userPermission=userPermission;
            temp.userConfigure=userConfigure;
            res.append(temp);
        }
    }
    sqlQuery.clear();
    sqlQuery.finish();
    return res;
}

// 插入单条数据
bool SqliteOperator::singleInsertData(sqlData &singledb)
{
//    qDebug()<<"in sql insert";
    QSqlQuery sqlQuery;
//    qDebug()<<singledb.userId;
//    qDebug()<<singledb.userName;
//    qDebug()<<singledb.userPassword;
//    qDebug()<<singledb.userPermission;
//    qDebug()<<singledb.userConfigure;
    sqlQuery.prepare("INSERT INTO userInfo VALUES(:userId,:userName,:userPassword,:userPermission,:userConfigure)");
    sqlQuery.bindValue(":userId", singledb.userId);
    sqlQuery.bindValue(":userName", singledb.userName);
    sqlQuery.bindValue(":userPassword", singledb.userPassword);
    sqlQuery.bindValue(":userPermission", singledb.userPermission);
    sqlQuery.bindValue(":userConfigure", singledb.userConfigure);
    if(!sqlQuery.exec())
    {
        qDebug() << "Error: Fail to insert data. " << sqlQuery.lastError();
        return false;
    }
    else
    {
    }
    sqlQuery.clear();
    sqlQuery.finish();
    return true;
}

// 插入多条数据
void SqliteOperator::moreInsertData(QList<sqlData>& moredb)
{
    // 进行多个数据的插入时，可以利用绑定进行批处理
    QSqlQuery sqlQuery;
    sqlQuery.prepare("INSERT INTO userInfo VALUES(?,?,?,?)");
    QVariantList idList,nameList,passwordList,permissionList,configureList;
    for(int i=0; i< moredb.size(); i++)
    {
        idList <<  moredb.at(i).userId;
        nameList << moredb.at(i).userName;
        passwordList << moredb.at(i).userPassword;
        permissionList << moredb.at(i).userPermission;
        configureList << moredb.at(i).userConfigure;
    }
    sqlQuery.addBindValue(idList);
    sqlQuery.addBindValue(nameList);
    sqlQuery.addBindValue(passwordList);
    sqlQuery.addBindValue(permissionList);
    sqlQuery.addBindValue(configureList);

    if (!sqlQuery.execBatch()) // 进行批处理，如果出错就输出错误
    {
        qDebug() << sqlQuery.lastError();
    }
    else
    {

    }
    sqlQuery.clear();
    sqlQuery.finish();
}

QStringList SqliteOperator::queryData(QString userId){
        QString select_sql = QString("select * from userInfo where userId = '%1'").arg(userId);
        QSqlQuery sql_query;
        QStringList list;
        if(!sql_query.exec(select_sql))
        {
            qDebug()<<sql_query.lastError();

        }
        else
        {
            while(sql_query.next())
            {
                list.append(sql_query.value(1).toString());
                list.append(sql_query.value(2).toString());
                list.append(sql_query.value(3).toString());
                list.append(sql_query.value(4).toString());
            }
        }
        if(list.count()==0)
        {
            list.append(QString("NONE"));
        }
        return list;
}
// 修改数据
bool SqliteOperator::modifyData(QString userId, QString userName, QString userPassword, QString userPermission, QString userConfigure)
{
    QSqlQuery sqlQuery;
    QString sql = "UPDATE userInfo SET userName=:userName,userPassword=:userPassword,userPermission=:userPermission,userConfigure=:userConfigure WHERE userId=:userId";

    sqlQuery.prepare(sql);
    sqlQuery.bindValue(":userName", userName);
    sqlQuery.bindValue(":userPassword", userPassword);
    sqlQuery.bindValue(":userPermission", userPermission);
    sqlQuery.bindValue(":userConfigure", userConfigure);
    sqlQuery.bindValue(":userId", userId);
//    qDebug()<<"upfate finish:";
    if(!sqlQuery.exec())
    {
        qDebug() << sqlQuery.lastError();
        return false;
    }
    else
    {
        qDebug() << "updated data success!";
        return true;
    }
    sqlQuery.clear();
    sqlQuery.finish();
}

// 删除数据
bool SqliteOperator::deleteData(QString userId)
{
    QSqlQuery sqlQuery;

    sqlQuery.exec(QString("DELETE FROM userInfo WHERE userId = %1").arg(userId));
    if(!sqlQuery.exec())
    {
        qDebug()<<sqlQuery.lastError();
        return false;
    }
    else
    {
        qDebug()<<"deleted data success!";
        return true;
    }
    sqlQuery.clear();
    sqlQuery.finish();
}

//删除数据表
void SqliteOperator::deleteTable(QString& tableName)
{
    QSqlQuery sqlQuery;

    sqlQuery.exec(QString("DROP TABLE %1").arg(tableName));
    if(sqlQuery.exec())
    {
        qDebug() << sqlQuery.lastError();
    }
    else
    {
        qDebug() << "deleted table success";
    }
    sqlQuery.clear();
    sqlQuery.finish();
}

void SqliteOperator::closeDb(void)
{
    database.close();
}
