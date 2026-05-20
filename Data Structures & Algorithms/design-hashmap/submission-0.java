

class MyHashMap {

    private class Pair {
        int key, value;
        Pair(int k, int v) { key = k; value = v; }
    }

    private final int SIZE = 1000;
    private List<Pair>[] buckets;

    public MyHashMap() {
        buckets = new ArrayList[SIZE];
        for (int i = 0; i < SIZE; i++) {
            buckets[i] = new ArrayList<>();
        }
    }

    private int hash(int key) {
        return key % SIZE;
    }

    public void put(int key, int value) {
        int index = hash(key);
        List<Pair> bucket = buckets[index];
        for (Pair p : bucket) {
            if (p.key == key) {
                p.value = value; // update existing key
                return;
            }
        }
        bucket.add(new Pair(key, value)); // add new key
    }

    public int get(int key) {
        int index = hash(key);
        List<Pair> bucket = buckets[index];
        for (Pair p : bucket) {
            if (p.key == key) return p.value;
        }
        return -1; // not found
    }

    public void remove(int key) {
        int index = hash(key);
        List<Pair> bucket = buckets[index];
        bucket.removeIf(p -> p.key == key);
    }
}


/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap obj = new MyHashMap();
 * obj.put(key,value);
 * int param_2 = obj.get(key);
 * obj.remove(key);
 */