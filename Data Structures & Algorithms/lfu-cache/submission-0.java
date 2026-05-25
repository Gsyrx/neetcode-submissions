class LFUCache {

    class Node {
        int key, value, freq;
        Node prev, next;

        Node(int k, int v) {
            key = k;
            value = v;
            freq = 1;
        }
    }

    class DLL {
        Node head, tail;
        int size;

        DLL() {
            head = new Node(-1, -1);
            tail = new Node(-1, -1);
            head.next = tail;
            tail.prev = head;
            size = 0;
        }

        void add(Node node) {
            node.next = head.next;
            node.prev = head;

            head.next.prev = node;
            head.next = node;

            size++;
        }

        void remove(Node node) {
            node.prev.next = node.next;
            node.next.prev = node.prev;
            size--;
        }

        Node removeLast() {
            if (size == 0) return null;

            Node last = tail.prev;
            remove(last);
            return last;
        }
    }

    int capacity;
    int minFreq;

    Map<Integer, Node> nodeMap;
    Map<Integer, DLL> freqMap;

    public LFUCache(int capacity) {

        this.capacity = capacity;
        this.minFreq = 0;

        nodeMap = new HashMap<>();
        freqMap = new HashMap<>();
    }

    public int get(int key) {

        if (!nodeMap.containsKey(key)) return -1;

        Node node = nodeMap.get(key);

        update(node);

        return node.value;
    }

    public void put(int key, int value) {

        if (capacity == 0) return;

        if (nodeMap.containsKey(key)) {

            Node node = nodeMap.get(key);
            node.value = value;

            update(node);

        } else {

            if (nodeMap.size() == capacity) {

                DLL minList = freqMap.get(minFreq);

                Node toRemove = minList.removeLast();

                nodeMap.remove(toRemove.key);
            }

            Node node = new Node(key, value);

            nodeMap.put(key, node);

            minFreq = 1;

            freqMap.putIfAbsent(1, new DLL());
            freqMap.get(1).add(node);
        }
    }

    private void update(Node node) {

        int freq = node.freq;

        DLL oldList = freqMap.get(freq);
        oldList.remove(node);

        if (freq == minFreq && oldList.size == 0) {
            minFreq++;
        }

        node.freq++;

        freqMap.putIfAbsent(node.freq, new DLL());
        freqMap.get(node.freq).add(node);
    }
}

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */