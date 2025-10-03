public class DynamicArray {
    
    private int[] arr;
    private int size;
    private int capacity;

    public DynamicArray(int capacity) throws IllegalArgumentException {
        if(capacity <= 0) {
            throw new IllegalArgumentException();
        }
        this.arr = new int[capacity];
        this.capacity = capacity;
        this.size = 0;
    }

    public int get(int i) {
        return arr[i];
    }

    public void set(int i, int n) throws IllegalArgumentException {
        if(i < 0 || i >= size) {
            throw new IllegalArgumentException();
        }
        arr[i] = n;
    }

    public void pushback(int n) {
        int insertAt = size;
        if(size + 1 > capacity){
            resize();
        }
        size++;
        arr[insertAt] = n;
    }

    public int popback() {
        size--;
        int res = arr[size];
        arr[size] = 0;
        return res;
    }

    private void resize() {
        this.capacity *= 2;
        int[] res = new int[capacity];
        for (int i = 0; i < size; i++){
            res[i] = arr[i];
        }
        arr = res;
    }

    public int getSize() {
        return size;
    }

    public int getCapacity() {
        return capacity;
    }
}
