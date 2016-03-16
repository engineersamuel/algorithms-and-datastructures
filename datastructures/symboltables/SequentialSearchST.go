package main

import "fmt"

type SequentialSearchST struct {
    first *Node;
}

type Node struct {
    key string;
    val int;
    next *Node;
}

func (st *SequentialSearchST) get(key string) int {
    for x := st.first; x != nil; x = x.next {
        if key == x.key {
            return x.val
        }
    }
    return -1
}

func (st *SequentialSearchST) put(key string, val int) {
    for x := st.first; x != nil; x = x.next {
        if key == x.key {
            x.val = val
            return
        }
    }
    st.first = &Node{key, val, st.first}
}

func main() {
    st := new(SequentialSearchST)

    st.put("a", 0)
    st.put("b", 1)
    st.put("c", 2)

    fmt.Println(fmt.Sprintf("c: %d", st.get("c")))
    fmt.Println(fmt.Sprintf("b: %d", st.get("b")))
    fmt.Println(fmt.Sprintf("a: %d", st.get("a")))
}
