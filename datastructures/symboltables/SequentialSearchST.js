"use strict";

function Node(key, val, next) {
    this.key = key;
    this.val = val;
    this.next = next;
}

class SequentialSearch {

    constructor() {
        this.first = null;
    }

    get(key) {
        for (let node = this.first; node != null; node = node.next) {
            if (node.key == key) {
                return node.val;
            }
        }
        return -1;
    }

    put(key, val) {
        for (let node = this.first; node != null; node = node.next) {
            if (node.key == key) {
                node.val = val;
                break;
            }
        }
        this.first = new Node(key, val, this.first);

    }
}

if (require.main === module) {

    let st = new SequentialSearch();
    st.put("a", 0);
    st.put("b", 1);
    st.put("c", 2);
    
    console.log(st.get("c"));
    console.log(st.get("b"));
    console.log(st.get("a"));
}

