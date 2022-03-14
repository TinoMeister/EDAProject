#include "../class/operation/operation.h"

/**
 * @brief Load data of Object.
 * Open the file of operations and get line by line and saves into the list.
 * @param op A list of operations.
 * @return Operation* return the operation.
 */
Operation* loadOpData(Operation* op);

/**
 * @brief Save data of Object.
 * Open the file of operations and insert all the information.
 * @param op A list of operations.
 */
void saveOpData(Operation* op);

/**
 * @brief Get the Total Op.
 * Get the higher numer of opertaion.
 * @param op A list of operations.
 * @return int return the total number of Operations.
 */
int getTotalOp(Operation* op);

/**
 * @brief Get the Shorter Time.
 * Get the lower timer to complete a job and return the list for each operation.
 * @param operations A list of operations.
 */
void showShorter(Operation* op);

/**
 * @brief Get the Longer Time
 * Get the high timer to complete a job and return the list for each operation.
 * @param operations A list of operations.
 */
void showLonger(Operation* op);

/**
 * @brief Get the Average Time
 * Get the average timer to complete a job considering all the alternatives and return the list for each operation.
 * @param operations A list of operations.
 */
void showAverage(Operation* op);