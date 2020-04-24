//
// Created by syr on 2020/4/18.
//

#include "Cursor.h"
#include "Table.h"
#include "LeafNode.h"


void *Cursor::get_value() {
    void *page = table->pager->get_page(page_num);
    return LeafNode(page).get_value(cell_num);
}

void Cursor::advance() {
    void *page = table->pager->get_page(page_num);
    LeafNode ln(page);
    cell_num += 1;
    // todo: Advance to next leaf node
}