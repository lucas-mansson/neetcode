public class DynamicArray<T> {
    
    private Object[] arr;
    private int size;
    private int capacity;

    public DynamicArray(int capacity) throws IllegalArgumentException {
        if(capacity <= 0) {
            throw new IllegalArgumentException();
        }
        this.arr = new Object[capacity];
        this.capacity = capacity;
        this.size = 0;
    }

    @SuppressWarnings("unchecked")
    public T get(int i) {
        return (T) arr[i];
    }

    public void set(int i, Object n) throws IndexOutOfBoundsException {
        if(i < 0 || i >= size) {
            throw new IndexOutOfBoundsException();
        }
        arr[i] = n;
    }

    public void pushback(Object n) {
        int insertAt = size;
        if(size + 1 > capacity){
            resize();
        }
        size++;
        arr[insertAt] = n;
    }

    @SuppressWarnings("unchecked")
    public T popback() throws IllegalStateException {
        if (size <= 0){
            throw new IllegalStateException();
        }
        size--;
        T res = (T) arr[size];
        arr[size] = null;
        return res;
    }

    private void resize() {
        this.capacity *= 2;
        Object[] res = new Object[capacity];
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
