#include <stdbool.h>

#define TAM 30

/**
 * @brief An struct type Operation.
 * 
 */
typedef struct 
{
    int id;         /**< int id */
    int idMachine;  /**< int  id Machine */
    int time;       /**< int time */
} Operation;

/**
 * @brief Add a new Operation.
 * Receives the list and the values and add a new operation.
 * After adding increases plus one in param total.
 * @param operations A list of operations.
 * @param total The actual size of the list.
 * @param size The max size of the list.
 * @param id The value id int to add.
 * @param idMachine The value idMachine int to add.
 * @param time The value time int to add.
 * @return true If the total is not higher then the size.
 * @return false If the total is higher then the size.
 */
bool addOperation(Operation* operations, int* total, int size, int id, int idMachine, int time);

/**
 * @brief Edit a Operation.
 * Receives the list and the values and edit the operation.
 * @param operations The list of operations.
 * @param index The index of the list to change.
 * @param size The max size of the list.
 * @param id The value id int.
 * @param idMachine The value idMachine int.
 * @param time The value time int.
 * @return true If the index is not higher then the size.
 * @return false If the index is higher then the size.
 */
bool editOperation(Operation* operations, int index, int size, int id, int idMachine, int time);

/**
 * @brief Delete a Operation.
 * Receives the list and the value index and delete the operation.
 * After deleting reduce minus one in param total.
 * @param operations The list of operations.
 * @param total The actual size of the list.
 * @param index The index of the list to change.
 * @param size The max size of the list.
 * @return true If the index is not higher then the size.
 * @return false If the index is higher then the size.
 */
bool deleteOperation(Operation* operations, int* total, int index, int size);