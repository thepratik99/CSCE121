#ifndef TEMP_DB
#define TEMP_DB

#include <string>
#include "LinkedList.h"

class TemperatureDatabase {
public:
	//default constructor
	TemperatureDatabase();
	//destructor
	~TemperatureDatabase();

	// Read the temperature records from the data file and populate the linked list
	void loadData(const std::string& data_file);

	// Read the queries from the query file and perform a series of queries
	void performQuery(const std::string& query_filename);

private:
	// Linked list to store the temperature records. You need to properly populate
	// this link list.
	LinkedList records;
};

#endif  // TEMP_DB
