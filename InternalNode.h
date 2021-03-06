//
// Created by syr on 2020/4/17.
//

#ifndef DB_DEMO_INTERNALNODE_H
#define DB_DEMO_INTERNALNODE_H
#include "Node.h"
#include "Pager.h"


/// Define Internal Node's layout
const uint32_t INTERNAL_NODE_NUM_KEYS_SIZE = sizeof(uint32_t);
const uint32_t INTERNAL_NODE_NUM_KEYS_OFFSET = COMMON_NODE_HEADER_SIZE;
const uint32_t INTERNAL_NODE_RIGHT_CHILD_SIZE = sizeof(uint32_t);
const uint32_t INTERNAL_NODE_RIGHT_CHILD_OFFSET = INTERNAL_NODE_NUM_KEYS_SIZE + INTERNAL_NODE_NUM_KEYS_OFFSET;
const uint32_t INTERNAL_NODE_HEADER_SIZE = COMMON_NODE_HEADER_SIZE + INTERNAL_NODE_NUM_KEYS_SIZE + INTERNAL_NODE_RIGHT_CHILD_SIZE;
const uint32_t INTERNAL_NODE_KEY_SIZE = sizeof(uint32_t);
const uint32_t INTERNAL_NODE_CHILD_SIZE = sizeof(uint32_t);
const uint32_t INTERNAL_NODE_CELL_SIZE = INTERNAL_NODE_KEY_SIZE + INTERNAL_NODE_CHILD_SIZE;

const uint32_t INTERNAL_NODE_MAX_CELLS = (PAGE_SIZE - INTERNAL_NODE_HEADER_SIZE) / INTERNAL_NODE_CELL_SIZE;

class Cursor;


/**
 * @brief 中间结点
 */
class InternalNode:public Node{
public:
    InternalNode(void *_node):Node(_node){}
    InternalNode(Node &_node):Node(_node.node){};
    uint32_t *get_num_keys();
    uint32_t *get_right_child();
    void *get_cell(uint32_t cell_num);
    uint32_t *get_child(uint32_t child_num);
    uint32_t *get_key(uint32_t key_num);
    uint32_t get_max_key();
    void init();
//    static Cursor *internal_node_find(Table *table, uint32_t page_num, uint32_t key);
    Cursor *find_key(Table *table, uint32_t key);
    uint32_t find_child(uint32_t key);
    void update_key(uint32_t old_key, uint32_t new_key);
    void insert(uint32_t child_page_num, Table *table, bool right_most);
};

#endif //DB_DEMO_INTERNALNODE_H
