class FreqStack {

    Map<Integer, Integer> freqMap;
    Map<Integer, Stack<Integer>> groupMap;

    int maxFreq;

    public FreqStack() {

        freqMap = new HashMap<>();
        groupMap = new HashMap<>();

        maxFreq = 0;
    }

    public void push(int val) {

        int freq = freqMap.getOrDefault(val, 0) + 1;

        freqMap.put(val, freq);

        maxFreq = Math.max(maxFreq, freq);

        groupMap.putIfAbsent(freq, new Stack<>());

        groupMap.get(freq).push(val);
    }

    public int pop() {

        int val = groupMap.get(maxFreq).pop();

        freqMap.put(val, freqMap.get(val) - 1);

        if (groupMap.get(maxFreq).isEmpty()) {
            maxFreq--;
        }

        return val;
    }
}

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack obj = new FreqStack();
 * obj.push(val);
 * int param_2 = obj.pop();
 */