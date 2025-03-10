#include "node.h"
#include<iostream>

Node::Node(bool sentinel){    
    next=nullptr;
    prev=nullptr;
    is_sentinel=true;
}

Node::Node(int v, Node *nxt, Node *prv){
    value=v;
    next=nxt;
    prev=prv;
    is_sentinel=false;
}

bool Node::is_sentinel_node()
{return is_sentinel;
}

int Node::get_value()
{return value;
}
