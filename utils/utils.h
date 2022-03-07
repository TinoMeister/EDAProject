#include "../class/operation/operation.h"

// FILE
// Load data of Object
bool loadOpData(Operation* operations, int* total);

// Save data of Object
bool saveOpData(Operation* operations, int total);

// FUNC
// Get the lower timer to complete a job and return the list for each operation
Operation* getShorter(Operation* operations, int total, int size);

// Get the high timer to complete a job and return the list for each operation
Operation* getLonger(Operation* operations, int total, int size);

// Get the average timer to complete a job considering all the alternatives and return the list for each operation
float getAverage(Operation* operations, int total, int id);