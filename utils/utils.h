#include "../class/operation/operation.h"

/**
 * @brief Load data of Object.
 * Open the file of operations and get line by line and saves into the list.
 * @param operations A list of operations.
 * @param total The actual size of the list.
 * @return true If can open the file and insert all into the list.
 * @return false If cannot open the file.
 */
bool loadOpData(Operation* operations, int* total);

/**
 * @brief Save data of Object.
 * Open the file of operations and insert all the information.
 * @param operations A list of operations.
 * @param total The actual size of the list.
 * @return true If can open the file and save all the content into it.
 * @return false If cannot open the file.
 */
bool saveOpData(Operation* operations, int total);

/**
 * @brief Get the highest id of operations.
 * 
 * @param operations A list of operations.
 * @param total The actual size of the list.
 * @return int The id of the operation.
 */
int getTotalOp(Operation* operations, int total);

/**
 * @brief Get the Shorter Time.
 * Get the lower timer to complete a job and return the list for each operation.
 * @param operations A list of operations.
 * @param total The actual size of the list.
 * @param size The max size of the list.
 * @return Operation* A list of operations in order.
 */
Operation* getShorter(Operation* operations, int total, int size);

/**
 * @brief Get the Longer Time
 * Get the high timer to complete a job and return the list for each operation.
 * @param operations A list of operations.
 * @param total The actual size of the list.
 * @param size The max size of the list.
 * @return Operation* A list of operations in order.
 */
Operation* getLonger(Operation* operations, int total, int size);

/**
 * @brief Get the Average Time
 * Get the average timer to complete a job considering all the alternatives and return the list for each operation.
 * @param operations A list of operations.
 * @param total The actual size of the list.
 * @param id The id of operation.
 * @return float The average.
 */
float getAverage(Operation* operations, int total, int id);