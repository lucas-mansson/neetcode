class MinStack {
    private int min;
    private List<Integer> a;

    public MinStack() {
        min = Integer.MAX_VALUE;
        a = new ArrayList<>();
    }
    
    public void push(int val) {
        if (val < min){
            min = val;
        }
        a.add(val);
    }
    
    public void pop() {
        int val = a.remove(a.size() - 1);

        if (val == min){
            int temp_min = Integer.MAX_VALUE;
            for (int i : a) {
                if (i < temp_min){
                    temp_min = i;
                }
            }
            min = temp_min;
        }
    }
    
    public int top() {
        return a.get(a.size()-1);
    }
    
    public int getMin() {
        return min;
    }
}
