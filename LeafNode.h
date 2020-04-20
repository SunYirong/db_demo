//
// Created by syr on 2020/4/17.
//

#ifndef DB_DEMO_LEAFNODE_H
#define DB_DEMO_LEAFNODE_H

#include "Node.h"
#include "Row.h"
#include "Pager.h"

class Cursor;

/*
 * Leaf node header layout
 */
const uint32_t LEAF_NODE_NUM_CELLS_SIZE = sizeof(uint32_t);
const uint32_t LEAF_NODE_NUM_CELLS_OFFSET = COMMON_NODE_HEADER_SIZE;
const uint32_t LEAF_NODE_HEADER_SIZE = COMMON_NODE_HEADER_SIZE + LEAF_NODE_NUM_CELLS_SIZE;

/*
 * Lead node body layout
 */
const uint32_t LEAF_NODE_KEY_SIZE = sizeof(uint32_t);
const uint32_t LEAF_NODE_KEY_OFFSET = 0;
const uint32_t LEAF_NODE_VALUE_SIZE = ROW_SIZE;
const uint32_t LEAF_NODE_VALUE_OFFSET = LEAF_NODE_KEY_OFFSET + LEAF_NODE_KEY_SIZE;
const uint32_t LEAF_NODE_CELL_SIZE = LEAF_NODE_KEY_SIZE + LEAF_NODE_VALUE_SIZE;
const uint32_t LEAF_NODE_SPACE_FOR_CELLS = PAGE_SIZE - LEAF_NODE_HEADER_SIZE;
const uint32_t LEAF_NODE_MAX_CELLS = LEAF_NODE_SPACE_FOR_CELLS / LEAF_NODE_CELL_SIZE;


class LeafNode : public Node {
public:
    LeafNode(void *n):Node(n){}
    void *get_num_cells();
    void *get_cell(uint32_t cell_num);
    void *get_key(uint32_t cell_num);
    void *get_value(uint32_t cell_num);
    void init();
    void insert(Cursor *cursor, uint32_t key, Row *value);
};

#endif //DB_DEMO_LEAFNODE_H