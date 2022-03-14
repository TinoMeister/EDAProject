#include <stdbool.h>

/**
 * @brief An struct type Operation.
 * 
 */
typedef struct oper
{
    int id;                 /**< id of operation */
    int idMachine;          /**< id Machine */
    int time;               /**< time of the Machine */
    struct oper *next;      /**< the next inserted*/
} Operation;

/**
 * @brief Add a new Operation.
 * Receives the list and the values and add a new operation.
 * After inserted into a operation, returns it with a pointer to the previous Operation.
 * @param op A list of operations.
 * @param id The value id int to add.
 * @param idMachine The value idMachine int to add.
 * @param time The value time int to add.
 * @return Operation* return the operation.
 */
Operation* addOperation(Operation* op, int id, int idMachine, int time);

/**
 * @brief Edit a Operation.
 * Receives the list and the values and edit the operation. 
 * @param op The list of operations.
 * @param index The index of the list to change.
 * @param id The value id int.
 * @param idMachine The value idMachine int.
 * @param time The value time int.
 * @return Operation* return the operation.
 */
Operation* editOperation(Operation* op, int index, int id, int idMachine, int time);

/**
 * @brief Delete a Operation.
 * Receives the list and the value index and delete the operation.
 * @param op The list of operations.
 * @param index The index of the list to change.
 * @return Operation* return the operation.
 */
Operation* deleteOperation(Operation* op, int index);