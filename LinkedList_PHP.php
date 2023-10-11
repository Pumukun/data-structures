<?php 
class Node {
    public $data;
    public $next;

    function __construct($pdata) {
        this->$data = $pdata; 
        this->$next = NULL;
    }
}

class LinkedList {
    public $head;

    function __construct() {
        $this->head = NULL;
    }

    function insert($pdata) {
        $new_node = new Node($pdata);
        if ($this->head == NULL) {
            $this->head = $new_node;
            return;
        }

        $tmp_node = $this->head;
        while ($tmp_node->next != NULL) {
            $tmp_node = $tmp_node->next;
        }
        $tmp_node->next = $new_node;
    }

    function pop() {
        if ($this->head == NULL) {
            return;
        }
        
        if ($this->head->next == NULL) {
            $this->head = NULL;
            return;
        }

        $prev_node = NULL;
        $tmp_node = $this->head;
        while ($tmp_node->next != NULL) {
            $prev_node = $tmp_node;
            $tmp_node = $tmp_node->next;
        }
        $prev_node->next = NULL;
    }
}
?>
