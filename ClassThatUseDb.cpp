#include "ClassThatUseDb.h"

ClassThatUseDb::ClassThatUseDb(DBConnectionInterface* dbHandle)
{
	_dbConnection = dbHandle;
}

void ClassThatUseDb::openConnection(std::string dbName)
{
	if (!dbName.empty())
		if (_dbConnection->open(dbName))
			_connectionEstablished = true;
}

std::string ClassThatUseDb::useConnection(std::string query)
{
	if (_connectionEstablished)
	{
		srand((unsigned)time(0));
		if (rand() % 2)
			return "DB wrong reply";	// ��������� ������ � 50%-������������: 
		//EXPECT_EQ ���������� ���������, EXPECT_CALL ���������� "�������" execQuery

		return _dbConnection->execQuery(query);	// ���������� ������ �� ������ �������
	}
	else
		return std::string();
}

void ClassThatUseDb::closeConnection()
{
	if (_connectionEstablished)
		_dbConnection->close();
}