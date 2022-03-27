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
 * @brief Get the Shorter object
 * Get the lower timer to complete a Operation.
 * @param op A list of operations.
 * @param id The id of the Operation.
 * @return Operation* return the Operation with the machine with lower time.
 */
Operation* getShorter(Operation* op, int id) ;

/**
 * @brief Get the Longer object
 * Get the high timer to complete a Operation.
 * @param op A list of operations.
 * @param id The id of the Operation.
 * @return Operation* return the Operation with the machine with higher time.
 */
Operation* getLonger(Operation* op, int id);

/**
 * @brief Get the Average object
 * Get the average timer to complete a operation.
 * @param op A list of operations.
 * @param id The id of the Operation.
 * @return float return the average or -1 if the id doesnt exists.
 */
float getAverage(Operation* op, int id);